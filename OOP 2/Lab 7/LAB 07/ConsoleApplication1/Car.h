#pragma once
#include <iostream>
using namespace std;

class Car {

	string CarName = " ";
	int cc = 0;
	string fuel = " ";
	string shift = " ";

public:

	string getName() {

		return CarName;
	}
	void setName(string name) {

		CarName = name;
	}

	int getCC() {

		return cc;
	}
	void setCC(int CVal) {

		cc = CVal;
	}

	string getFuel() {

		return fuel;
	}
	void setFuel(string f) {

		fuel = f;
	}

	string getShift() {

		return shift;
	}
	void setShift(string s) {

		shift = s;
	}
};

Car SearchByCarName(Car* ptr, string name) {

	Car obj;

	for (int i = 0; i < 4; i++) {

		if (ptr[i].getName() == name) {

			return ptr[i];
		}
 	}

	return obj;
}

Car SearchByCC(Car* ptr, int cVal) {

	Car obj;

	for (int i = 0; i < 4; i++) {

		if (ptr[i].getCC() == cVal) {

			return ptr[i];
		}
	}

	return obj;
}