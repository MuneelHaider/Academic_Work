#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

class Distance {

	int Feet;
	int Inches;

public:

	Distance(int FeetVal = 0, int InchesVal = 0) {

		Feet = FeetVal;
		Inches = InchesVal;
	}

	int getInches() {

		return Inches;
	}

	int getFeets() {

		return Feet;
	}

	Distance operator++() {

		++Feet;
		++Inches;

		while (Inches >= 12) {

			Feet++;
			Inches -= 12;
		}

		return *this;
	}

	Distance operator++(int) {

		Feet++;
		Inches++;

		while (Inches >= 12) {

			Feet++;
			Inches -= 12;
		}

		return *this;
	}

	Distance operator--() {

		--Feet;
		--Inches;

		while (Inches >= 12) {

			Feet++;
			Inches -= 12;
		}

		return *this;
	}

	Distance operator--(int) {

		Feet--;
		Inches--;

		while (Inches >= 12) {

			Feet++;
			Inches -= 12;
		}

		return *this;
	}
};