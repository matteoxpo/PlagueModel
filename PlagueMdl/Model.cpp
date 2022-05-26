#include "Model.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>


// конструктор по умолчанию
Model::Model() :
	xSize{0},
	ySize{0},
	peoplesCount{0},
	doctorsCount{0},
	ppls{nullptr},
	docs{nullptr}
{};
//конструктор с параметрами
Model::Model(float sizeX = 0, float sizeY = 0, int countPpls = 0, int countDocs = 0) {
	if (countPpls < 0) throw std::logic_error("Negative number of people!");
	if (countDocs < 0) throw std::logic_error("Negative number of doctors!");

	xSize = sizeX;
	ySize = sizeY;

	peoplesCount = countPpls;
	doctorsCount = countDocs;
	if (0 != countPpls)
		ppls = new SimplePeople[countPpls];
	else
		ppls = nullptr;

	if (0 != countDocs)
		docs = new Doctor[countDocs];
	else
		docs = nullptr;
}
// консутрктор копирования
Model::Model(const Model& other): 
	xSize{other.xSize},
	ySize{other.ySize},
	peoplesCount{other.peoplesCount},
	ppls{new SimplePeople[other.peoplesCount]},
	doctorsCount{other.doctorsCount},
	docs{ new Doctor[other.doctorsCount] }
{
	for (int i = 0; i < peoplesCount; i++) {
		ppls[i] = other.ppls[i];
	}
	for (int i = 0; i < doctorsCount; i++) {
		docs[i] = other.docs[i];
	}
}

// конструктор пермещения
Model::Model(Model&& other) noexcept :
	xSize{ other.xSize },
	ySize{ other.ySize },
	doctorsCount {other.doctorsCount},
	peoplesCount {other.peoplesCount},
	ppls { other.ppls},
	docs {other.docs} 
{
	other.ppls = nullptr;
	other.docs = nullptr;
}

//оператор присваивания
Model Model::operator=(const Model& other) {
	destroy();
	xSize = other.xSize;
	ySize = other.ySize;
	peoplesCount = other.peoplesCount;
	doctorsCount = other.doctorsCount;
	ppls = new SimplePeople[peoplesCount];
	docs = new Doctor[doctorsCount];

	for (int i = 0; i < peoplesCount; i++) {
		ppls[i] = other.ppls[i];
	}
	for (int i = 0; i < doctorsCount; i++) {
		docs[i] = other.docs[i];
	}

	return *this;
}
//оператор перемещения
Model& Model::operator=(Model&& other) noexcept {
	destroy();
	xSize = other.xSize;
	ySize = other.ySize;

	peoplesCount = other.peoplesCount;
	doctorsCount = other.doctorsCount;

	ppls = other.ppls;
	docs = other.docs;

	other.ppls = nullptr;
	other.docs = nullptr;
	return *this;
}
Model::~Model() {
	destroy();
}

void Model::destroy() {
	if (ppls)
		delete[] ppls;
	if (docs)
		delete[] docs;
}


// возврат  человека; доктора по индексу
SimplePeople Model::getPplByInd(int ind) const {
	if (ind > peoplesCount - 1) throw std::logic_error("There are fewer people than the index.");
	if (ind < 0) throw std::logic_error("The index cannot be negative.");
	return ppls[ind];
}
Doctor Model::getDocByInd(int ind) const {
	if (ind > doctorsCount - 1) throw std::logic_error("There are fewer doctors than the index.");
	if (ind < 0) throw std::logic_error("The index cannot be negative.");
	return docs[ind];
}

// добавление человека; доктора
void Model::pushPeople(SimplePeople p) {
	peoplesCount++;
	SimplePeople* tPpls = new SimplePeople[peoplesCount ];
	for (int i = 0; i < peoplesCount - 1; i++) {
		tPpls[i] = ppls[i];
	}
	delete[] ppls;
	ppls = tPpls;
	ppls[peoplesCount - 1] = p;
}
void Model::pushDoctor(Doctor d) {
	doctorsCount++;
	Doctor* tDocs = new Doctor[doctorsCount];
	for (int i = 0; i < doctorsCount - 1; i++) {
		tDocs[i] = docs[i];
	}
	delete[] docs;
	docs = tDocs;
	docs[doctorsCount - 1] = d;

}

// удаление человека; доктора по индексу
void Model::delPplByInd(int ind) {
	if (ind < 0) throw std::logic_error("Negative index!");
	if (ind > peoplesCount) throw std::logic_error("Index is more than the number of peoples!");
	if (peoplesCount == 0) throw std::logic_error("Nothing to delete!");

	peoplesCount--;
	SimplePeople* tPpls = new SimplePeople[peoplesCount];
	for (int i = 0, j = 0; i < peoplesCount + 1; i++, j++) {
		if (i == ind)
			i++;
		tPpls[j] = ppls[i];
	}
	delete[] ppls;
	ppls = tPpls;
}
void Model::delDocByInd(int ind) {
	if (ind < 0) throw std::logic_error("Negative index!");
	if (ind > doctorsCount) throw std::logic_error("Index is more than the number of peoples!");
	if (doctorsCount == 0) throw std::logic_error("Nothing to delete!");

	doctorsCount--;
	Doctor* tDocs = new Doctor[doctorsCount];
	for (int i = 0, j = 0; i < doctorsCount + 1; i++, j++) {
		if (i == ind)
			i++;
		tDocs[j] = docs[i];
	}
	delete[] docs;
	docs = tDocs;
}

// методы подсчета расстония от человека к человеку/доктору
float Model::distancePplDoc(SimplePeople ppl, Doctor doc) const {
	float xppl = ppl.getX();
	float yppl = ppl.getY();

	float xdoc = doc.getX();
	float ydoc = doc.getY();

	float dist = (float)sqrt(pow(xppl - xdoc, 2) + pow(yppl - ydoc, 2));
	return dist;
}
float Model::distancePplPpl(SimplePeople ppl1, SimplePeople ppl2) const {
	float xppl1 = ppl1.getX();
	float yppl1 = ppl1.getY();

	float xppl2 = ppl2.getX();
	float yppl2 = ppl2.getY();

	float dist = (float)sqrt(pow(xppl1 - xppl2, 2) + pow(yppl1 - yppl2, 2));
	return dist;

}

// обновление состояний агентов с временем dt
void Model::updateAgentStatus(int dt) {
	int infected = 0;
	int treated = 0;
	for (int i = 0; i < dt; i++) {
		// проверка на выход за рамки поля, изменение направления в противном случае
		if (ppls[i].getX() > xSize) {
			ppls[i].setX(xSize);
			ppls[i].setSpeedX(-ppls[i].getSpeedX());
		}
		if (ppls[i].getX() < -xSize) {
			ppls[i].setX(-xSize);
			ppls[i].setSpeedX(-ppls[i].getSpeedX());
		}
		if (ppls[i].getY() > ySize) {
			ppls[i].setY(ySize);
			ppls[i].setSpeedY(-ppls[i].getSpeedY());
		}
		if (ppls[i].getY() < -ySize) {
			ppls[i].setY(-ySize);
			ppls[i].setSpeedY(-ppls[i].getSpeedY());
		}

		// меняем инукубационный период людей
		for (int j = 0; j < peoplesCount; j++) {
			if (ppls[j].getIncubationPerion() != 0) {
				ppls[j].setIncubationPeriod(ppls[j].getIncubationPerion() - 1);
				if (ppls[j].getIncubationPerion() == 0) {
					ppls[j].setInfective(true);
				}
			}
		}

		// проверка заражённых рядом, заражение(установка инкубационного периода)
		for (int j = 0; j < peoplesCount; j++) {
			if (distancePplPpl(ppls[i], ppls[j]) < 2) {
				if (true == ppls[j].getSickStatus()) {
					if (false == ppls[i].getSickStatus()) {
						ppls[i].setIncubationPeriod(2);
						infected++;
					}
				}
			}
		}

		// доктора лечат всех рядом стоящих людей на момент dt
		for (int j = 0; j < doctorsCount; j++) {
			if (distancePplDoc(ppls[i], docs[j]) < 2) {
				ppls[i].sickStatusUpdate(0);
				ppls[i].setIncubationPeriod(0);
				ppls[i].setInfective(false);
				treated++;
			}
		}
		ppls[i].positionUpdate();
		docs[i].positionUpdate();
	}

	/*std::cout << std::endl << "For the period dt:" << dt << std::endl;
	std::cout << infected << "people was infected." << std::endl;
	std::cout << treated << "people was treated." << std::endl;
	*/
}


std::ostream& operator <<(std::ostream& out, Model& m) {
	if (0 == m.peoplesCount)
		out << "No peoples" << std::endl;
	else {
		for (int i = 0; i < m.peoplesCount; i++) {
			out << "People #" << i + 1 << std::endl;
			out << m.ppls[i];
		}
	}
	if (0 == m.doctorsCount)
		out << "No doctors" << std::endl;
	else {
		for (int i = 0; i < m.doctorsCount; i++) {
			out << "Doctor #" << i + 1 << std::endl;
			out << m.docs[i];
		}
	}
	return out;
}