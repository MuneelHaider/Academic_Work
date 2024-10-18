#pragma once

#include <iostream>
using namespace std;

class Date {

	int Day;
	int Month;
	int Year;

public:

	Date(int D = 0, int M = 0, int Y = 0) {

		Day = D;
		Month = M;
		Year = Y;
	}

	bool operator>(Date& obj1) {

		if (Year > obj1.Year && Month > obj1.Month && Day >= obj1.Day) {

			return false;
		}
		else {

			return true;
		}
	}

	bool operator<(Date& obj1) {

		if (Year < obj1.Year && Month < obj1.Month && Day <= obj1.Day) {

			return false;
		}
		else {

			return true;
		}
	}

	bool operator==(Date& obj1) {

		if (Year == obj1.Year && Month == obj1.Month && Day == obj1.Day) {

			return true;
		}
		else {

			return false;
		}
	}
};