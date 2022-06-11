#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <math.h>
#include "Model.h"
#include <memory>


std::shared_ptr<SimplePeople> inputPeople() {
	std::shared_ptr<SimplePeople> Pptr = std::make_shared<SimplePeople>();
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
	if (true == sickStat) {
		while (true == safetyFlag) {
			if (false == Pptr->getSickStatus()) safetyFlag = false;
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
	}
	else incPer = 0;
	if (0 == incPer && true == sickStat) {
		inf = true;
	}
	else inf = false;
	Pptr->setX(xC);
	Pptr->setY(yC);
	Pptr->setSpeedX(xS);
	Pptr->setSpeedY(yS);
	Pptr->sickStatusUpdate(sickStat, (sickStat) ? incPer : 0);
	Pptr->setInfective(sickStat);
	Pptr->setIncubationPeriod(incPer);
	return Pptr;
}
std::shared_ptr<Doctor> inputDoctor() {
	std::shared_ptr<Doctor> Dptr = std::make_shared<Doctor>();
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

	Dptr->setX(xC);
	Dptr->setY(yC);
	Dptr->setSpeedX(xS);
	Dptr->setSpeedY(yS);
	/*d.setX(xC);
	d.setY(yC);
	d.setSpeedX(xS);
	d.setSpeedY(yS);*/
	return Dptr;
}

void Menu() {
	std::cout << "Plague model - agents doctors\n agents - people or doctors \n peoples can be infected, doctors can treat people...\n";
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
	catch (std::bad_alloc& err) {
		std::cerr << "Caught: " << err.what() << std::endl;
		std::cerr << "Type: " << typeid(err).name() << std::endl;
		std::cout << std::endl;
		std::cout << "end of program execution";
		exit(EXIT_FAILURE);
	}
	auto Pptr = std::make_shared<SimplePeople>();
	for (int i = 0; i < pplsCount; i++, safetyFlag = true) {
		while (true == safetyFlag) {
			std::cout << "Enter the data about people #" << i << ":" << std::endl;
			try {
				Pptr = inputPeople();
				if (abs(Pptr->getX()) > abs(xSize)) throw std::range_error("The person outside the map");
				if (abs(Pptr->getY()) > abs(ySize)) throw std::range_error("The person outside the map");
				safetyFlag = false;
				M.setPeople(Pptr, i);
			}
			catch (std::range_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	safetyFlag = true;
	
	
	auto Dptr = std::make_shared<Doctor>();
	for (int i = 0; i < docsCount; i++, safetyFlag = true) {
		while (true == safetyFlag) {
			std::cout << "Enter the data about doctor #" << i << ":" << std::endl;
			try {
				Dptr = inputDoctor();
				if (abs(Dptr->getX()) > abs(xSize)) throw std::range_error("The person outside the map");
				if (abs(Dptr->getY()) > abs(ySize)) throw std::range_error("The person outside the map");
				safetyFlag = false;
				M.setDoctor(Dptr, i);
			}
			catch (std::range_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	safetyFlag = true;

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

	//ввод команды
	int ind = 0;
	int dt = 0;
	SimplePeople p;
	Doctor d;
	while (true) {
		std::cout << std::endl;
		for (int i = 0; i < (sizeof(menu) / sizeof(menu[0])); i++) {
			std::cout << menu[i] << std::endl;
		}
		safetyFlag = true;
		while (true == safetyFlag) {
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

		safetyFlag = true;

		switch (command) {
		case 1:
			std::cout << M;
			break;
		case 2:
			std::cout << M.getHowManySick();
			break;
		case 3:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Input index: ";
				input.clear();
				std::cin >> input;
				try {
					ind = stoi(input);
					safetyFlag = false;
				}
				catch (std::invalid_argument& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
			}
			try {
				p = M.getPplByInd(ind);
			}
			catch (std::logic_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
				break;
			}
			//std::cout << p;
			break;
		case 4:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Input index: ";
				input.clear();
				std::cin >> input;
				try {
					ind = stoi(input);
					safetyFlag = false;
				}
				catch (std::invalid_argument& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
			}
			try {
				d = M.getDocByInd(ind);
			}
			catch (std::logic_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
				break;
			}
			std::cout << d;
			break;
		case 5:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Enter the data about people " << std::endl;
				try {
					Pptr = inputPeople();
					if (abs(Pptr->getX()) > abs(xSize)) throw std::range_error("The person outside the map");
					if (abs(Pptr->getY()) > abs(ySize)) throw std::range_error("The person outside the map");
					M.push(Pptr);
					safetyFlag = false;
				}
				catch (std::bad_alloc& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
					std::cout << "end of program execution";
					exit(EXIT_FAILURE);
				}
				catch (std::range_error& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
			}
			break;
		case 6:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Enter the data about doctor " << std::endl;
				try {
					Dptr = inputDoctor();
					if (abs(Dptr->getX()) > abs(xSize)) throw std::range_error("The person outside the map");
					if (abs(Dptr->getY()) > abs(ySize)) throw std::range_error("The person outside the map");
					M.push(Dptr);
					safetyFlag = false;
				}
				catch (std::bad_alloc& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
					std::cout << "end of program execution";
					exit(EXIT_FAILURE);
				}
				catch (std::range_error& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
			}
			break;
		case 7:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Input index: ";
				input.clear();
				std::cin >> input;
				try {
					ind = stoi(input);
					safetyFlag = false;
				}
				catch (std::invalid_argument& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
			}
			try {
				M.delPplByInd(ind);
			}
			catch (std::logic_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
			}
			break;
		case 8:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Input index: ";
				input.clear();
				std::cin >> input;
				try {
					ind = stoi(input);
					safetyFlag = false;
				}
				catch (std::invalid_argument& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
			}
			try {
				M.delDocByInd(ind);
			}
			catch (std::logic_error& err) {
				std::cerr << "Caught: " << err.what() << std::endl;
				std::cerr << "Type: " << typeid(err).name() << std::endl;
				std::cout << std::endl;
			}
			break;
		case 9:
			safetyFlag = true;
			while (true == safetyFlag) {
				std::cout << "Input dt: ";
				input.clear();
				std::cin >> input;
				try {
					dt = stoi(input);
					safetyFlag = false;
				}
				catch (std::invalid_argument& err) {
					std::cerr << "Caught: " << err.what() << std::endl;
					std::cerr << "Type: " << typeid(err).name() << std::endl;
					std::cout << std::endl;
				}
				M.updateAgentStatus(dt);
				break;
		case 10:
			std::cout << std::endl << "Thx for using, bye";
			return;
			break;

			}
		}
	}
}

int main()
{
	Menu();
}
