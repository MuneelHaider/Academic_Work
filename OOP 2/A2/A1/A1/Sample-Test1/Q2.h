#pragma once
#include <iostream>
using namespace std;

class Date {

	int day;
	int month;
	int year;

public:

	Date() {

		day = 0;
		month = 0;
		year = 0;
	}
	Date(int d, int m, int y) {

		if (m < 1 || m > 12) {

			m = 1;
		}

		day = d;
		month = m;
		year = y;
	}
	Date(Date& obj) {

		if (obj.month < 1 || obj.month > 12) {

			obj.month = 1;
		}

		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
	}

	int getDay() {

		return this->day;
	}
	void setDay(int d) {

		this->day = d;
	}

	int getMonth() {

		return this->month;
	}
	void setMonth(int m) {

		if (m < 1 || m > 12) {

			m = 1;
		}

		this->month = m;
	}

	int getYear() {

		return this->year;
	}
	void setYear(int y) {

		this->year = y;
	}

	void displayDate();
	void nextDay();
};

void Date::displayDate() {

	cout << this->day << "/" << this->month << "/" << this->year << endl << endl;
}

void Date::nextDay() {

	bool leap = true;

	if (this->year % 4 == 0) {

		leap = true;
	}
	else {

		leap = false;
	}

	if (leap == true) {

		this->day += 1;

		if (this->day >= 30) {

			this->month += 1;
			this->day = 1;
		}
	}
	else {

		this->day += 1;

		if (this->day >= 29) {

			this->month += 1;
			this->day = 1;
		}
	}

	if (this->month > 12) {

		this->month = 1;
		this->year += 1;
	}
}