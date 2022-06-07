#pragma once
#include <vector>
#include <iostream>
#include "SimplePeople.h" 
#include "Doctor.h" 

class Model
{
	float xSize;
	float ySize;

	std::vector <SimplePeople> ppls;

	std::vector <Doctor> docs;

public:
	Model();
	Model(float, float, int, int);
	Model(const Model&);
	Model(Model&&) noexcept;
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
		return ppls.size();
	}
	// возврат количества докторов
	inline int getDocCount() const {
		return docs.size();
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


};

