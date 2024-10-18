#pragma once

#include <iostream>
using namespace std;

class Distance {

	int feet = 0;
	int inches = 0;

public:

	Distance(int feetVal = 0, int inchesVal = 0) {

		while(inchesVal >= 12) {

			feetVal++;
			inchesVal -= 12;
		}

		inches = inchesVal;
		feet = feetVal;
	}

	void setFeets(int f) {

		feet = f;
	}

	void setInches(int i) {

		while (i >= 12) {

			feet++;
			i -= 12;
		}

		inches = i;
	}

	int getFeets() const {

		return feet;
	}

	int getInches() const {

		return inches;
	}

	Distance operator+(Distance &obj1) {

		feet += obj1.feet;
		inches += obj1.inches;

		return *this;
	}

	Distance operator-(Distance& obj1) {

		feet -= obj1.feet;
		inches -= obj1.inches;

		return *this;
	}
};