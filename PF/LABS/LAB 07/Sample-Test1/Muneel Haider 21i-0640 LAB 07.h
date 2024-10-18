#pragma once

#include <iostream>
using namespace std;

class Time {

	int days = 0;
	int weeks = 0;
	int months = 0;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;

public:

	Time() {

		days = 0;
		weeks = 0;
		months = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int hoursVal, int minutesVal, int secondsVal):hours(hoursVal),minutes(minutesVal), seconds(secondsVal) {
		days = 0;
		weeks = 0;
		months = 0;
		
	}

	int setseconds(int s) {

		seconds = s;
	}

	int setminutes(int m) {

		minutes = m;
	}

	int sethours(int h) {

		hours = h;
	}

	int setdays(int d) {

		days = d;
	}

	int setweeks(int w) {

		weeks = w;
	}

	int setmonths(int m) {

		months = m;
	}

	int getdays() {

		return days;
	}

	int getweeks() {

		return weeks;
	}

	int getmonths() {

		return months;
	}

	int getHours() {

		return hours;
	}

	int getMinutes() {

		return minutes;
	}

	int getSeconds() {

		return seconds;
	}

	int retSeconds() {

		return seconds;
	}

	int retMinutes() {

		return minutes;
	}

	int retHours() {

		return hours;
	}

	void setData(int, int, int);
	void getData();
	void calculateTime(Time);
	void calculateDays();
};

void Time::setData(int hoursVal, int minutesVal, int secondsVal) {

	hours = hoursVal;
	minutes = minutesVal;
	seconds = secondsVal;
}

void Time::getData() {

	cout << hours << ":" << minutes << ":" << seconds << endl;
	cout << months << ":" << weeks << ":" << days << endl;
}

void Time::calculateTime(Time obj) {

	seconds += obj.seconds;
	minutes += obj.minutes;
	hours += obj.hours;
	int mod = 0;

	if (seconds >= 60) {

		mod = seconds / 60;
		seconds = seconds % 60;
		minutes += mod;
	}

	if (minutes >= 60) {

		mod = minutes / 60;
		minutes = minutes % 60;
		hours += mod;
	}
}

void Time::calculateDays() {

	while (hours > 24) {

		days += 1;
		hours -= 24;
	}

	while (days > 7) {

		weeks++;
		days -= 7;
	}

	while (weeks >= 4) {

		months++;
		weeks -= 4;
	}
}

class Product {

	string name;
	int price;
	int quantity;
	static int totalProduct;

public:

	Product() {
		counter();
	}

	Product(string nameVal, int priceVal, int quantityVal):name(nameVal),price(priceVal),quantity(quantityVal) {

		counter();
	}

	void getData() {

		cout << name << endl;
		cout << price << endl;
		cout << quantity << endl;
	}

	static void counter() {

		totalProduct += 1;
	}

	static int countProduct() {

		return totalProduct;
	}
};

int Product::totalProduct = 0;


class Matrix {

	int** array;

public:

	Matrix(int n = 0) {

		array = new int* [3];
		for (int i = 0; i < 3; i++) {

			*(array + i) = new int[3];
		}

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				array[i][j] = n;
			}
		}
	}

	Matrix dot(Matrix obj) {

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				obj.array[i][j] *= array[i][j];
			}
		}

		return obj;
	}

	int retrieveValue(int r, int c) {

		return array[r][c];
	}
};