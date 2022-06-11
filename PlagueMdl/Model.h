#pragma once
#include <vector>
#include <iostream>
#include "SimplePeople.h" 
#include "Doctor.h" 

class Model
{
	float xSize;
	float ySize;

	std::vector <std::shared_ptr<SimplePeople>> ppls;
	std::vector <std::shared_ptr<Doctor>> docs;

	float distance(std::shared_ptr<SimplePeople >, std::shared_ptr<Doctor>) const;
	float distance(std::shared_ptr<SimplePeople >, std::shared_ptr<SimplePeople >) const;
public:
	Model();
	Model(float, float, int, int);




	inline void setXSize(float x) {
		xSize = x;
	}
	inline void setYSize(float y) {
		ySize = y;
	}
	inline void setPeople(std::shared_ptr<SimplePeople> p, int ind) {
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


	void push(std::shared_ptr<People>);


	void delPplByInd(int);
	void delDocByInd(int);

	void updateAgentStatus(int);

	friend std::ostream& operator <<(std::ostream&, Model&);
};

