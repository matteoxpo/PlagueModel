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
	
	// ������� ������� �����
	inline float getXSize() const {
		return xSize;
	}
	inline float getYSize() const {
		return ySize;
	}

	int getHowManySick() const;

	// ������� ���������� �������
	inline int getPplCount() const {
		return ppls.size();
	}
	// ������� ���������� ��������
	inline int getDocCount() const {
		return docs.size();
	}
	// ����� ������� �� �������
	SimplePeople getPplByInd(int) const;
	// ����� ������� �� �������
	Doctor getDocByInd(int) const;



	// ���������� ��������
	void pushPeople(SimplePeople);
	// ���������� �������
	void pushDoctor(Doctor);

	void delPplByInd(int);
	void delDocByInd(int);


	void updateAgentStatus(int);


	friend std::ostream& operator <<(std::ostream&, Model&);
	float distancePplDoc(SimplePeople, Doctor) const;
	float distancePplPpl(SimplePeople, SimplePeople) const;


};

