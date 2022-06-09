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
	std::vector <std::shared_ptr<Doctor>> docs;
	std::vector <pair < std::shared_ptr<People>, std::shared_ptr<People> >> all;

public:
	Model();
	Model(float, float, int, int);




	inline void setXSize(float x) {
		xSize = x;
	}
	inline void setYSize(float y) {
		ySize = y;
	}
	inline void setPeople(SimplePeople p, int ind) {
		ppls[ind] = p;
	}
	inline void setDoctor(std::shared_ptr<Doctor> Dptr, int ind) {
		docs[ind] = Dptr;
	}
	
	inline float getXSize() const {
		return xSize;
	}
	inline float getYSize() const {
		return ySize;
	}

	int getHowManySick() const;

	inline int getPplCount() const {
		return ppls.size();
	}
	inline int getDocCount() const {
		return docs.size();
	}
	SimplePeople getPplByInd(int) const;
	Doctor getDocByInd(int) const;



	void pushPeople(SimplePeople);
	void pushDoctor(std::shared_ptr<Doctor>);

	void delPplByInd(int);
	void delDocByInd(int);


	void updateAgentStatus(int);


	friend std::ostream& operator <<(std::ostream&, Model&);
	float distancePplDoc(SimplePeople, std::shared_ptr<Doctor> Dptr) const;
	float distancePplPpl(SimplePeople, SimplePeople) const;


};

