#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <math.h>
#include "Model.h"


void inputPeople(SimplePeople &p) {
	float xC = 0;
	float yC = 0;
	float xS = 0;
	float yS = 0;
	bool sickStat = 0;

	int incPer = 0;
	bool inf = 0;

	bool safetyFlag = true;
	std::string input;
	//xCoord
	while (true == safetyFlag) {
		std::cout << "Input x coordinate: ";
		input.clear();
		std::cin >> input;

		try {
			xC = stof(input); 
			safetyFlag = false;
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	safetyFlag = true;

	//yCoord
	while (true == safetyFlag) {
		std::cout << "Input y coordinate: ";
		input.clear();
		std::cin >> input;

		try {
			yC = stof(input);
			safetyFlag = false;
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	safetyFlag = true;
	
	//xSpeed
	while (true == safetyFlag) {
		std::cout << "Enter x speed: ";
		input.clear();
		std::cin >> input;
		try {
			xS = stof(input);
			safetyFlag = false;
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	safetyFlag = true;
	
	//ySpeed
	while (true == safetyFlag) {
		std::cout << "Enter y speed: ";
		input.clear();
		std::cin >> input;
		try {
			yS = stof(input);
			safetyFlag = false;
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	safetyFlag = true;

	//sickStatus infective
	while (true == safetyFlag) {
		std::cout << "Enter sick status: ";
		input.clear();
		std::cin >> input;
		try {
			if (input == "true") input = "1";
			if (input == "false") input = "0";
			sickStat = stoi(input);
			safetyFlag = false;
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	safetyFlag = true;

	//incubationPeriod
	while (true == safetyFlag) {
		if (false == p.getSickStatus()) safetyFlag = false;
		std::cout << "Enter incubation period: ";
		input.clear();
		std::cin >> input;
		try {
			incPer = stoi(input);
			if (incPer < 0) throw std::logic_error("Negative incubation period");
			safetyFlag = false;
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
		catch (std::logic_error& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	
	if (0 == incPer && true == sickStat) {
		inf = true;
	}
	else inf = false;
	SimplePeople p1(xC,yC,xS,yS,sickStat,incPer,inf);
	p = p1;
	/*p.setX(xC);
	p.setY(yC);
	p.setSpeedX(xS);
	p.setSpeedY(yS);
	p.sickStatusUpdate(sickStat);
	p.setInfective(sickStat);
	p.setIncubationPeriod(incPer);*/
}

void Menu() {

	std::string menu[] = {
		" 1 - Print info about peoples & doctors" ,
		" 2 - Print how many peoples are sick",
		" 3 - Printf information about a person by number/index/id",
		" 4 - Printf information about a doctor by number/index/id",
		" 5 - Push one more person in model",
		" 6 - Push one more doctor in model",
		" 7 - Delete a person by number/index/id",
		" 8 - Delete a doctor by number/index/id",
		" 9 - Make a change over time dt ",
		"10 - Exit"
	};

	std::cout << "Creating model." << std::endl;
	float xSize = -1, ySize = -1;
	int pplsCount = -1, docsCount = -1;
	
	int command = 0;

	bool safetyFlag = true;
	std::string input;

	while (-1 == xSize) {
		std::cout << "Input x size of map: ";
		input.clear();
		std::cin >> input;

		try {
			xSize = abs(stof(input));
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}

	while (-1 == ySize) {
		std::cout << "Input y size of map: ";
		input.clear();
		std::cin >> input;

		try {
			ySize = abs(stof(input));
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	
	while (-1 == pplsCount) {
		std::cout << "Enter the number of people: ";
		input.clear();
		std::cin >> input;

		try {
			pplsCount = stoi(input);
			if (ySize < 0) throw std::logic_error("Negative number of people");
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
		catch (std::logic_error& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}

	while (-1 == docsCount) {
		std::cout << "Enter the number of doctors: ";
		input.clear();
		std::cin >> input;

		try {
			docsCount = stoi(input);
			if (ySize < 0) throw std::logic_error("Negative number of people");
		}
		catch (std::invalid_argument& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
		catch (std::logic_error& err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}
	Model M;
	try {
		Model test(xSize, ySize, pplsCount, docsCount);
		M = test;
	}
	catch(std::bad_alloc &err){
		std::cerr << "Caught: " << err.what() << std::endl;
		std::cerr << "Type: " << typeid(err).name() << std::endl;
		std::cout << std::endl;
		exit(EXIT_FAILURE);
	}
	SimplePeople p;
	for (int i = 0; i < pplsCount; i++, safetyFlag = true) {
		while (true == safetyFlag) {
			std::cout << "Enter the data about people #" << i << ":" << std::endl;
			try {
				inputPeople(p);
				if (abs(p.getX()) > abs(xSize)) throw std::range_error("The person outside the map");
				if (abs(p.getY()) > abs(ySize)) throw std::range_error("The person outside the map");
				safetyFlag = false;
				M.setPeople(p, i);
			}
			catch (std::range_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
			}
		}
		
	}
	safetyFlag = true;

	// вывод меню
	for (int i = 0; i < (sizeof(menu) / sizeof(menu[0])); i++) {
		std::cout << menu[i] << std::endl;
	}
	//ввод команды
	while (true == safetyFlag ) {
		std::cout << std::endl << "Enter the command number: ";
		try {
			std::cin >> input;
			command = stoi(input);
			if (command > 10 || command < 1)
				throw std::logic_error("Unknow command");
			safetyFlag = false;
		}
		catch (std::invalid_argument err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
		catch (std::logic_error err) {
			std::cerr << "Caught: " << err.what() << std::endl;
			std::cerr << "Type: " << typeid(err).name() << std::endl;
			std::cout << std::endl;
		}
	}

	switch (command) {
	case 1:
	}
}


int main()
{
	SimplePeople p;
	inputPeople(p);

}
