#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Date {

	string day;
	string month;
	string year;
	string hour;
	bool Day_used;
	string date;

public:

	Date(string dVal = "", string mVal = "", string yVal = "", string hVal = "", bool Dayval = false) {

		day = dVal;
		month = mVal;
		year = yVal;
		hour = hVal;
		Day_used = Dayval;
		
		this->setDate(dVal, mVal, yVal, hVal, Dayval);
	}

	void setDay(string dVal) {

		day = dVal;
	}
	string getDay() {

		return day;
	}

	void setMonth(string mVal) {

		month = mVal;
	}
	string getMonth() {

		return month;
	}

	void setYear(string yVal) {

		year = yVal;
	}
	string getYear() {

		return year;
	}

	void setHour(string hVal) {

		hour = hVal;
	}
	string getHour() {

		return hour;
	}

	void setUsed(bool tt) {

		Day_used = tt;
	}
	bool getUsed() {

		return Day_used;
	}

	void setDate(string dVal, string mVal, string yVal, string hVal, bool tt) {

		day = dVal;
		month = mVal;
		year = yVal;
		hour = hVal;
		date = dVal + "/" + mVal + "/" + yVal + " - " + hVal + " hours";
		Day_used = tt;
	}
	string getDate() {

		return date;
	}

};