#pragma once

#include <iostream>
using namespace std;

class Money {

	int dollars;
	int cents;

public:

	Money() {

		dollars = 0;
		cents = 0;
	}

	Money(int D, int C) {

		while (cents > 100) {

			dollars++;
			cents -= 100;
		}

		dollars = D;
		cents = C;
	}

	int getDollars() {

		return dollars;
	}

	bool operator==(Money& right) {

		if (dollars == right.dollars && cents == right.cents) {

			return true;
		}
		else {

			return false;
		}
	}

	Money operator+(Money& right) {

		while (cents > 100) {

			dollars++;
			cents -= 100;
		}

		dollars += right.dollars;
		cents += right.cents;
		
		return *this;
	}

	Money operator-(Money& right) {

		while (cents > 100) {

			dollars++;
			cents -= 100;
		}

		dollars -= right.dollars;
		cents -= right.cents;

		return *this;
	}

	Money operator*(int number) {

		while (cents > 100) {

			dollars++;
			cents -= 100;
		}

		dollars *= number;
		cents *= number;

		return *this;
	}

	Money operator/(int number) {

		dollars /= number;
		cents /= number;

		return *this;
	}

	~Money() {

	}
};