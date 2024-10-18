#pragma once
#include <iostream>
using namespace std;

class DateAndTime {

	int day;
	int month;
	int year;
	int second;
	int minute;
	int hour;
	char meridiem;

public:

	DateAndTime() {

		day = 1;
		month = 1;
		year = 1;
		second = 0;
		minute = 0;
		hour = 0;
		meridiem = '\0';
	}
	DateAndTime(int d, int m, int y, int s, int mon, int h, char meri) {

		if (m < 1 || m > 12) {

			m = 1;
		}
		if(d < 1 || d > 31) {
		
			d = 1;
		}
		if (s < 0 || s > 59) {

			s = 1;
		}
		if (mon < 0 || mon > 59) {

			mon = 1;
		}
		if (h < 0 || h > 23) {

			s = 1;
		}

		day = d;
		month = m;
		year = y;
		second = s;
		minute = mon;
		hour = h;
		meridiem = meri;

	}
	DateAndTime(DateAndTime& obj) {

		if (obj.month < 1 || obj.month > 12) {

			obj.month = 1;
		}

		if (obj.day < 1 || obj.day > 31) {

			obj.day = 1;
		}
		if (obj.second < 0 || obj.second > 59) {

			obj.second = 0;
		}
		if (obj.minute < 0 || obj.minute > 59) {

			obj.minute = 0;
		}
		if (obj.hour < 0 || obj.hour > 23) {

			obj.hour = 0;
		}

		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
		this->second = obj.second;
		this->minute = obj.minute;
		this->hour = obj.hour;
		this->meridiem = obj.meridiem;
	}

	int getDay() {

		return this->day;
	}
	void setDay(int d) {

		if (d < 1 || d > 31) {

			d = 1;
		}

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

	int getSec() {

		return second;
	}
	void setSec(int s) {

		if (s < 1 || s > 59) {

			s = 1;
		}

		second = s;
	}

	int getMin() {

		return minute;
	}
	void setMin(int m) {

		if (m < 1 || m > 12) {

			m = 1;
		}

		minute = m;
	}

	int getHour() {

		return hour;
	}
	void setHour(int h) {

		if (h < 1 || h > 23) {

			h = 1;
		}

		hour = h;
	}

	char getMeridiem() {

		return meridiem;
	}
	void setMeridiem(char m) {

		meridiem = m;
	}


	void displayDateAndTime();
	void nextDay();
	void tick();
};

void DateAndTime::displayDateAndTime() {

	cout << this->day << "/" << this->month << "/" << this->year << endl;
	cout << this->second << " Seconds\t" << this->minute << " Minutes\t" << this->hour << " Hours\t" << this->meridiem << "m" << endl;
}

void DateAndTime::nextDay() {

	bool leap = true;

	if (this->year % 4 == 0) {

		leap = true;
	}
	else {

		leap = false;
	}

	if (leap == true) {

		this->day += 1;

		if (this->day >= 31) {

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

void DateAndTime::tick() {

	second += 1;

	if (second > 59) {

		second = 0;
		minute += 1;

		if(minute > 59) {
		
			minute = 0;
			hour += 1;

			if (hour > 11) {
				 
				if (hour > 23) {

					hour = 0;
				}

				if (meridiem == 'a') {

					meridiem = 'p';
				}
				else {

					meridiem = 'a';
					nextDay();
				}
			}
		}
	}
}