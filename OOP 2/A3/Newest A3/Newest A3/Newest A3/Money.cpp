#include "pch.h"
#include <iostream>
#include "Money.h"
using namespace std;

Cent::Cent() {

	c = 0;
}
Cent::Cent(int num) {

	if (num < 0) {

		num = 0;
	}

	c = num;
}

void Cent::setCent(int v) {

	c = v;
}
float Cent::getC() {

	return c;
}
void Cent::increase1Cent() {

	c += 1;
}
void Cent::decrease5Cent() {

	c -= 5;
}
void Cent::increase5Cent() {

	c += 5;
}

Cent Cent::operator+=(Cent& obj) {

	this->c += obj.c;
	return *this;
}
Cent Cent::operator-=(Cent& obj) {

	this->c -= obj.c;
	return *this;
}

/***************************************************/

Nickel::Nickel() {

	n = 0;
}
Nickel::Nickel(int num) {

	if (num < 0) {

		num = 0;
	}

	n = num;
}

void Nickel::setNickel(int s) {

	n = s;
}
int Nickel::getN() {

	return n;
}
int Nickel::getNickels() {

	return n;
}
void Nickel::increase1Nickel() {

	n += 1;
}
void Nickel::decrease5Nickel() {

	n -= 5;
}
void Nickel::decrease1Nickel() {

	n -= 1;
}
void Nickel::increase5Nickel() {

	n += 5;
}

Nickel Nickel::operator+=(Nickel& obj) {

	this->n += obj.n;
	return *this;
}
Nickel Nickel::operator-=(Nickel& obj) {

	this->n -= obj.n;
	return *this;
}

/***************************************************/

Dollar::Dollar() {

	d = 0;
}
Dollar::Dollar(int num) {

	if (num < 0) {

		num = 0;
	}

	d = num;
}

void Dollar::setDollar(int s) {

	d = s;
}
float Dollar::getD() {

	return d;
}
void Dollar::increase1Dollar() {

	d += 1;
}
void Dollar::decrease1Dollar() {

	d -= 1;
}

Dollar Dollar::operator+=(Dollar& obj) {

	this->d += obj.d;
	return *this;
}
Dollar Dollar::operator-=(Dollar& obj) {

	this->d -= obj.d;
	return *this;
}

/***************************************************/

Quarter::Quarter() {

	q = 0;
}
Quarter::Quarter(int num) {

	if (num < 0) {

		num = 0;
	}

	q = num;
}

void Quarter::setQuarter(int s) {

	q = s;
}
int Quarter::getQ() {

	return q;
}
int Quarter::getQuarters() {

	return q;
}

void Quarter::increase1Quarter() {

	q += 1;
}
void Quarter::decrease4Quarter() {

	q -= 4;
}
void Quarter::decrease1Quarter() {

	q -= 1;
}
void Quarter::increase4Quarter() {

	q += 4;
}
void Quarter::increase5Quarter() {

	q += 5;
}

Quarter Quarter::operator+=(Quarter& obj) {

	this->q += obj.q;
	return *this;
}
Quarter Quarter::operator-=(Quarter& obj) {

	this->q -= obj.q;
	return *this;
}

/***************************************************/

Money::Money() {

	original = 0;
}
Money::Money(double num) {

	if (num < 0) {

		num = 0;
	}

	original = num * 100;

	int temp = num;
	float temp1 = 0;
	float temp2 = 0;
	int counter = 0;

	dollars.setDollar(temp);

	temp1 = num - temp;
	temp1 *= 100;
	counter = 0;

	temp2 = temp1 / 25;
	while (temp1 > 25) {

		temp1 -= 25;
		counter++;
	}

	quarters.setQuarter(counter);

	counter = 0;
	temp2 = temp1 / 5;
	while (temp1 > 4) {

		temp1 -= 5;
		counter++;
	}

	nickels.setNickel(counter);

	counter = 0;
	temp2 = temp1 / 1;

	while (temp1 > 0) {

		temp1 -= 1;
		counter++;
	}
	cents.setCent(counter);
}

int Money::getDollars() {

	return this->dollars.getD();
}
int Money::getQuarters() {

	return this->quarters.getQ();
}
int Money::getNickels() {

	return this->nickels.getN();
}
int Money::getCents() {

	return this->cents.getC();
}

Money Money::operator+(Money m) {

	this->dollars += m.dollars;
	this->quarters += m.quarters;
	this->nickels += m.nickels;
	this->cents += m.cents;

	this->MoneyChecker();

	return *this;
}

Money Money::operator-(Money m) {

	this->dollars -= m.dollars;
	this->quarters -= m.quarters;
	this->nickels -= m.nickels;
	this->cents -= m.cents;

	this->MoneyChecker();

	return *this;
}

Money Money::operator+(Dollar d) {

	this->dollars += d;
	return *this;
}

Money Money::operator-(Dollar d) {

	this->dollars -= d;
	return *this;
}

Money Money::operator+(Nickel d) {

	this->nickels += d;
	this->MoneyChecker();

	return *this;
}

Money Money::operator-(Nickel d) {

	this->nickels -= d;
	this->MoneyChecker();

	return *this;
}

Money Money::operator+(Quarter d) {

	this->quarters += d;
	this->MoneyChecker();

	return *this;
}
Money Money::operator-(Quarter d) {

	this->quarters -= d;
	this->MoneyChecker();

	return *this;
}

Money Money::operator+(Cent d) {

	this->cents += d;
	this->MoneyChecker();

	return *this;
}

Money Money::operator-(Cent d) {

	this->cents -= d;
	this->MoneyChecker();

	return *this;
}

Money Money::operator++(int n) {

	if (this->quarters.getQ() == 3) {

		if (this->nickels.getN() > 0 || this->cents.getC() > 0) {
			this->quarters.setQuarter(0);
			this->nickels.setNickel(0);
			this->cents.setCent(0);
			this->dollars.increase1Dollar();

		}
		else {

			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
	}
	else if (this->quarters.getQ() == 2) {

		if (this->nickels.getN() >= 2 && this->cents.getC() >= 2) {

			this->quarters.increase1Quarter();
			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
		else {

			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
	}
	else if (this->quarters.getQ() == 1) {

		if (this->nickels.getN() >= 2 && this->cents.getC() >= 2) {

			this->quarters.increase1Quarter();
			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
		else {

			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
	}
	else if (this->quarters.getQ() == 0) {

		if (this->nickels.getN() >= 2 && this->cents.getC() >= 2) {

			this->quarters.increase1Quarter();
			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
		else {

			this->nickels.setNickel(0);
			this->cents.setCent(0);
		}
	}

	return *this;
}

Money Money::operator--(int n) {

	this->nickels.setNickel(0);
	this->cents.setCent(0);

	return *this;
}

bool Money::operator>=(Money& obj) {

	this->MoneyChecker();

	if (this->dollars.getD() > obj.dollars.getD()) {

		return true;
	}
	else if (this->dollars.getD() < obj.dollars.getD()) {

		return false;
	}

	if (this->quarters.getQ() >= obj.quarters.getQ()) {

		if (this->nickels.getN() >= obj.nickels.getN()) {

			if (this->cents.getC() >= obj.cents.getC()) {

				return true;
			}
		}
	}

	return false;
}

bool Money::operator<=(Money& obj) {

	this->MoneyChecker();

	if (this->dollars.getD() <= obj.dollars.getD()) {

		if (this->quarters.getQ() <= obj.quarters.getQ()) {

			if (this->nickels.getN() <= obj.nickels.getN()) {

				if (this->cents.getC() <= obj.cents.getC()) {

					return true;
				}
			}
		}
	}

	return false;
}

Quarter Money::operator!() {

	this->MoneyChecker();

	Quarter temp;

	while (this->dollars.getD() > 0) {

		this->dollars.decrease1Dollar();
		this->quarters.increase4Quarter();
	}

	temp = this->quarters;

	return temp;
}

Nickel Money::operator~() {

	this->MoneyChecker();

	Nickel temp;

	while (this->dollars.getD() > 0) {

		this->dollars.decrease1Dollar();
		this->quarters.increase4Quarter();
	}

	while (this->quarters.getQ() > 0) {

		this->quarters.decrease1Quarter();
		this->nickels.increase5Nickel();
	}

	temp = this->nickels;

	return temp;
}

Money Money::operator/(int n) {

	int comp;

	comp = original / n;

	float temp1 = 0;
	float temp2 = 0;
	int counter = 0;

	temp2 = comp / 100;
	temp1 = comp % 100;

	dollars.setDollar(temp2);

	temp2 = temp1 / 25;
	while (temp1 > 25) {

		temp1 -= 25;
		counter++;
	}

	quarters.setQuarter(counter);

	counter = 0;
	temp2 = temp1 / 5;
	while (temp1 > 4) {

		temp1 -= 5;
		counter++;
	}

	nickels.setNickel(counter);

	counter = 0;
	temp2 = temp1 / 1;

	while (temp1 > 0) {

		temp1 -= 1;
		counter++;
	}
	cents.setCent(counter);

	return *this;
}

Money Money::operator*(int n) {

	int comp;

	comp = original * n;

	float temp1 = 0;
	float temp2 = 0;
	int counter = 0;

	temp2 = comp / 100;
	temp1 = comp % 100;

	dollars.setDollar(temp2);

	temp2 = temp1 / 25;
	while (temp1 > 25) {

		temp1 -= 25;
		counter++;
	}

	quarters.setQuarter(counter);

	counter = 0;
	temp2 = temp1 / 5;
	while (temp1 > 4) {

		temp1 -= 5;
		counter++;
	}

	nickels.setNickel(counter);

	counter = 0;
	temp2 = temp1 / 1;

	while (temp1 > 0) {

		temp1 -= 1;
		counter++;
	}
	cents.setCent(counter);

	return *this;
}

// Self-Made Functions
void Money::MoneyChecker() {

	if (this->cents.getC() >= 5) {

		while (this->cents.getC() >= 5) {

			this->nickels.increase1Nickel();
			this->cents.decrease5Cent();
		}
	}

	if (this->nickels.getN() >= 5) {

		while (this->nickels.getN() >= 5) {

			this->quarters.increase1Quarter();
			this->nickels.decrease5Nickel();
		}
	}

	if (this->quarters.getQ() >= 4) {

		while (this->quarters.getQ() >= 4) {

			this->quarters.decrease4Quarter();
			this->dollars.increase1Dollar();
		}
	}

	if (this->cents.getC() < 0) {

		while (this->cents.getC() < 0) {

			this->cents.increase5Cent();
			this->nickels.decrease1Nickel();
		}
	}

	if (this->nickels.getN() < 0) {

		while (this->nickels.getN() < 0) {

			this->nickels.increase5Nickel();
			this->quarters.decrease1Quarter();
		}
	}

	if (this->quarters.getQ() < 0) {

		while (this->quarters.getQ() < 0) {

			this->quarters.increase4Quarter();
			this->dollars.decrease1Dollar();
		}
	}
}