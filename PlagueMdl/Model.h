#pragma once
#include <iostream>
#include "SimplePeople.h" 
#include "Doctor.h" 

class Model
{
public:
	Model();
	Model(float, float, int, int);
	// все шо ниже блоксхемить
	Model(const Model&);
	Model(Model&&) noexcept;
	~Model();
	Model operator =(const Model&);
	Model& operator =( Model&&) noexcept;




	inline void setXSize(float x) {
		xSize = x;
	}
	inline void setYSize(float y) {
		ySize = y;
	}
	inline void setPeople(SimplePeople p, int ind) {
		ppls[ind] = p;
	}
	inline void setDoctor(Doctor d, int ind) {
		docs[ind] = d;
	}
	
	// возврат размера карты
	inline float getXSize() const {
		return xSize;
	}
	inline float getYSize() const {
		return ySize;
	}

	int getHowManySick() const;

	// возврат количества человек
	inline int getPplCount() const {
		return peoplesCount;
	}
	// возврат количества докторов
	inline int getDocCount() const {
		return doctorsCount;
	}
	// поиск челвека по индексу
	SimplePeople getPplByInd(int) const;
	// поиск доктора по индексу
	Doctor getDocByInd(int) const;



	// добавление человека
	void pushPeople(SimplePeople);
	// добавление доктора
	void pushDoctor(Doctor);

	void delPplByInd(int);
	void delDocByInd(int);


	void updateAgentStatus(int);


	friend std::ostream& operator <<(std::ostream&, Model&);
	float distancePplDoc(SimplePeople, Doctor) const;
	float distancePplPpl(SimplePeople, SimplePeople) const;

private:
	float xSize;
	float ySize;

	SimplePeople* ppls;
	int peoplesCount;
	
	Doctor* docs;
	int doctorsCount;

	void destroy();
};

