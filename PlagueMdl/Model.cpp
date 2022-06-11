#include "Model.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iterator>

Model::Model() :
	xSize{ 0 },
	ySize{ 0 },
	ppls{ 0 },
	docs{ 0 }
{};
Model::Model(float sizeX = 0, float sizeY = 0, int countPpls = 0, int countDocs = 0) {
	if (countPpls < 0) throw std::logic_error("Negative number of people!");
	if (countDocs < 0) throw std::logic_error("Negative number of doctors!");

	xSize = sizeX;
	ySize = sizeY;

	if (0 == countPpls)
		ppls.clear();
	else
		ppls.resize(countPpls);


	if (0 == countDocs)
		docs.clear();
	else
		docs.resize(countDocs);

}


int Model::getHowManySick() const {
	int countSick = 0;
	for (int i = 0; i < ppls.size(); i++) {
		if (true == ppls[i]->getSickStatus())
			countSick++;
	}
	return countSick;
}

SimplePeople Model::getPplByInd(int ind) const {
	if (ind > ppls.size() - 1) throw std::logic_error("There are fewer people than the index.");
	if (ind < 0) throw std::logic_error("The index cannot be negative.");
	return *ppls[ind];
}
Doctor Model::getDocByInd(int ind) const {
	if (ind > docs.size() - 1) throw std::logic_error("There are fewer doctors than the index.");
	if (ind < 0) throw std::logic_error("The index cannot be negative.");
	return *docs[ind];
}
/*
SimplePeople p;
m.push(p);

*/
void Model::push(std::shared_ptr<People> p){

	if (typeid(*p) == typeid(SimplePeople))
		ppls.push_back(std::dynamic_pointer_cast <SimplePeople>(p));
	if (typeid(*p) == typeid(Doctor))
		docs.push_back(std::dynamic_pointer_cast<Doctor>(p));
}

//void Model::push(std::shared_ptr<SimplePeople> p) {
//	ppls.resize(ppls.size() + 1);
//	ppls[ppls.size() - 1] = p;
//}
//void Model::push(std::shared_ptr<Doctor> d) {
//	docs.resize(docs.size() + 1);
//	docs[docs.size() - 1] = d;
//}


void Model::delPplByInd(int ind) {
	if (ind < 0) throw std::logic_error("Negative index!");
	if (ind > ppls.size()) throw std::logic_error("Index is more than the number of peoples!");
	if (ppls.size() == 0) throw std::logic_error("Nothing to delete!");
	ppls.erase(ppls.begin() + ind);
}
void Model::delDocByInd(int ind) {
	if (ind < 0) throw std::logic_error("Negative index!");
	if (ind > docs.size()) throw std::logic_error("Index is more than the number of peoples!");
	if (docs.size() == 0) throw std::logic_error("Nothing to delete!");
	docs.erase(docs.begin() + ind);
}


float Model::distance(std::shared_ptr<SimplePeople > ppl, std::shared_ptr<Doctor> doc) const {
	float xppl = ppl->getX();
	float yppl = ppl->getY();

	float xdoc = doc->getX();
	float ydoc = doc->getY();

	float dist = (float)sqrt(pow(xppl - xdoc, 2) + pow(yppl - ydoc, 2));
	return dist;
}
float Model::distance(std::shared_ptr<SimplePeople > ppl1, std::shared_ptr<SimplePeople > ppl2) const {
	float xppl1 = ppl1->getX();
	float yppl1 = ppl1->getY();

	float xppl2 = ppl2->getX();
	float yppl2 = ppl2->getY();

	float dist = (float)sqrt(pow(xppl1 - xppl2, 2) + pow(yppl1 - yppl2, 2));
	return dist;

}




void Model::updateAgentStatus(int dt) {
	for (int k = 0; k < dt; k++) {

		if (0 != docs.size()  || 0 != ppls.size()) {
			for (int i = 0; i < ppls.size(); i++) {
				for (int j = 0; j < docs.size(); j++) {
					for (int j = 0; j < docs.size(); j++) {
						if (distance(ppls[i], docs[j]) < 2) {
							ppls[i]->sickStatusUpdate(0, 0);
							ppls[i]->setIncubationPeriod(0);
							ppls[i]->setInfective(false);
						}
					}
				}
			}
		}

		if (0 != ppls.size()) {
			for (int i = 0; i < ppls.size(); i++) {
				ppls[i]->positionUpdate(1);


				if (ppls[i]->getX() > xSize) {
					ppls[i]->setX(xSize);
					ppls[i]->setSpeedX(-ppls[i]->getSpeedX());
				}
				if (ppls[i]->getX() < -xSize) {
					ppls[i]->setX(-xSize);
					ppls[i]->setSpeedX(-ppls[i]->getSpeedX());
				}
				if (ppls[i]->getY() > ySize) {
					ppls[i]->setY(ySize);
					ppls[i]->setSpeedY(-ppls[i]->getSpeedY());
				}
				if (ppls[i]->getY() < -ySize) {
					ppls[i]->setY(-ySize);
					ppls[i]->setSpeedY(-ppls[i]->getSpeedY());
				}


				for (int j = 0; j < ppls.size(); j++) {
					if (ppls[j]->getIncubationPerion() != 0) {
						ppls[j]->setIncubationPeriod(ppls[j]->getIncubationPerion() - 1);
						if (ppls[j]->getIncubationPerion() == 0) {
							ppls[j]->setInfective(true);
						}
					}

				}
				for (int j = 0; j < ppls.size(); j++) {
					if (distance(ppls[i], ppls[j]) < 2) {
						if (true == ppls[j]->getSickStatus() && ppls[j]->getIncubationPerion() == 0) {
							if (false == ppls[i]->getSickStatus()) {
								ppls[i]->sickStatusUpdate(true, 2);
							}
						}
					}
				}

			}
		}
		
		if (0 != docs.size()) {
			for (int i = 0; i < docs.size(); i++) {
				docs[i]->positionUpdate(1);

				if (docs[i]->getX() > xSize) {
					docs[i]->setX(xSize);
					docs[i]->setSpeedX(-docs[i]->getSpeedX());
				}
				if (docs[i]->getX() < -xSize) {
					docs[i]->setX(-xSize);
					docs[i]->setSpeedX(-docs[i]->getSpeedX());
				}
				if (docs[i]->getY() > ySize) {
					docs[i]->setY(ySize);
					docs[i]->setSpeedY(-docs[i]->getSpeedY());
				}
				if (docs[i]->getY() < -ySize) {
					docs[i]->setY(-ySize);
					docs[i]->setSpeedY(-docs[i]->getSpeedY());
				}
			}
		}
		
		
	}
}


std::ostream& operator <<(std::ostream& out, Model& m) {
	if (0 == m.ppls.size())
		out << "No peoples" << std::endl;
	else {
		for (int i = 0; i < m.ppls.size(); i++) {
			if (m.ppls[i] == nullptr) continue;
			out << "People #" << i + 1 << std::endl;
			out << m.ppls[i];
		}
	}
	if (0 == m.docs.size())
		out << std::endl <<"No doctors" << std::endl;
	else {
		out << std::endl;
		for (int i = 0; i < m.docs.size(); i++) {
			if (m.docs[i] == nullptr) break;
			out << "Doctor #" << i + 1 << std::endl;
			out << m.docs[i];
		}
	}
	return out;
}