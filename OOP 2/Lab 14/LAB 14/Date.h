#pragma once
#include <iostream>
using namespace std;

class Date {

protected:

	int day;
	int month;
	int year;

public:

	Date(int d = 0, int m = 0, int y = 0) {

		day = d;
		month = m;
		year = y;
	}

	void setDay(int d) {

		day = d;
	}
	int getDat() {

		return day;
	}

	void setMonth(int m) {

		month = m;
	}
	int getMonth() {

		return month;
	}

	void setYear(int y) {

		year = y;
	}
	int getYear() {

		return year;
	}

	void display() {

		cout << "Date:\t" << day << "/" << month << "/" << year << endl;
	}
};

class DateTime : public Date {

protected:

	int hours;
	int minutes;
	int seconds;

public:

	DateTime(int d = 0, int m = 0, int y = 0, int h = 0, int min = 0, int s = 0) {

		day = d;
		month = m;
		year = y;
		hours = h;
		minutes = min;
		seconds = s;
	}

	void setHours(int h) {

		hours = h;
	}
	int getHours() {

		return hours;
	}

	void setMin(int m) {

		minutes = m;
	}
	int getMin() {

		return minutes;
	}

	void setSec(int s) {

		seconds = s;
	}
	int getSec() {

		return seconds;
	}

	void display() {

		cout << day << "/" << month << "/" << year << "\t" << seconds << ":" << minutes << ":" << hours << endl << endl;
	}
};