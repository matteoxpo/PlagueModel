#pragma once
#include <iostream>
#include "SimplePeople.h" 
#include "Doctor.h" 

class Model
{
	float xSize;
	float ySize;

	SimplePeople* ppls;
	int peoplesCount;
	
	Doctor* docs;
	int doctorsCount;

	void destroy();
	float distancePplDoc(SimplePeople, Doctor) const;
	float distancePplPpl(SimplePeople, SimplePeople) const;
public:
	Model();
	Model(float, float, int, int);
	// ��� �� ���� �����������
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
	
	// ������� ������� �����
	inline float getXSize() const {
		return xSize;
	}
	inline float getYSize() const {
		return ySize;
	}


	// ������� ���������� �������
	inline int getPplCount() const {
		return peoplesCount;
	}
	// ������� ���������� ��������
	inline int getDocCount() const {
		return doctorsCount;
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
};

