/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 1			*/

#include "pch.h"
#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;

Rational::Rational() {

	numerator = 0;
	denom = 1;
}

int GCD(int numerator, int denom) {

	int result = 1;

	for (int i = 2; numerator >= i && denom >= i; i++) {

		if (numerator % i == 0 && denom % i == 0) {

			result = i;
		}
	}

	return result;
}

void Simplify(int& numerator, int& denom) {

	int temp = GCD(numerator, denom);

	numerator /= temp;
	denom /= temp;
}

Rational::Rational(int numeratorVal, int denomVal) {

	Simplify(numeratorVal, denomVal);

	numerator = numeratorVal;
	denom = denomVal;
}

Rational::Rational(const Rational& copy) {

	numerator = copy.numerator;
	denom = copy.denom;
}// copy constructor to initialize the Rational form existing Rational //object
// Binary Operators
// Assignment Operator

Rational Rational::operator=(const Rational& x) {

	numerator = x.numerator;
	denom = x.denom;

	return *this;
}

// Arithmetic Operators
Rational Rational::operator+(const Rational& x) const {

	Rational temp(numerator, denom);

	int LCM = (denom * x.denom) / GCD(denom, x.denom);

	int NumeratorVal = (numerator * LCM / denom) + (x.numerator * LCM / x.denom);

	int Factor = GCD(NumeratorVal, LCM);

	temp.numerator = NumeratorVal / Factor;

	temp.denom = LCM / Factor;

	return temp;
}

Rational Rational::operator-(const Rational& x) const {

	Rational temp(numerator, denom);

	int LCM = GCD(denom, x.denom);

	int Num1 = numerator * LCM;
	int Num2 = x.numerator * LCM;
	int Result = 0;

	Result = (Num1 - Num2);
	Simplify(Result, LCM);

	temp.numerator = Result;
	temp.denom = x.denom;

	return temp;
}

Rational Rational::operator*(const Rational& x) const {

	Rational temp(numerator, denom);

	int Num1 = temp.numerator * x.numerator;
	int Num2 = temp.denom * x.denom;

	Simplify(Num1, Num2);

	temp.numerator = Num1;
	temp.denom = Num2;

	return temp;
}

Rational Rational::operator/(const Rational& x) const {

	Rational temp(numerator, denom);
	Rational Inverse(x.numerator, x.denom);

	int dummy = Inverse.numerator;
	Inverse.numerator = Inverse.denom;
	Inverse.denom = dummy;

	int Num1 = temp.numerator * Inverse.numerator;
	int Num2 = temp.denom * Inverse.denom;

	Simplify(Num1, Num2);

	temp.numerator = Num1;
	temp.denom = Num2;

	return temp;
}

// Compound Arithmetic Operators
Rational Rational::operator += (const Rational& x) {

	Rational temp(x.numerator, x.denom);
	Simplify(temp.numerator, temp.denom);

	numerator += temp.numerator;
	denom += temp.denom;

	return *this;
}

Rational Rational::operator -= (const Rational& x) {

	Rational temp(x.numerator, x.denom);
	Simplify(temp.numerator, temp.denom);

	numerator -= temp.numerator;

	if (denom != 1 && temp.denom != 1) {

		denom -= temp.denom;
	}

	return *this;
}

Rational Rational::operator *= (const Rational& x) {

	Rational temp(x.numerator, x.denom);
	Simplify(temp.numerator, temp.denom);

	numerator *= temp.numerator;
	denom *= temp.denom;

	return *this;
}

Rational Rational::operator /= (const Rational& x) {

	Rational temp(x.numerator, x.denom);
	Simplify(temp.numerator, temp.denom);

	numerator /= temp.numerator;
	denom /= temp.denom;

	return *this;
}

// Logical Operators
bool Rational::operator == (const Rational& other) const {

	if (numerator == other.numerator && denom == other.denom) {

		return true;
	}
	else {

		return false;
	}
}

bool Rational::operator < (const Rational& other) const {

	if (numerator < other.numerator && denom < other.denom) {

		return true;
	}
	else {

		return false;
	}
}

bool Rational::operator > (const Rational& other) const {

	if (numerator > other.numerator && denom > other.denom) {

		return true;
	}
	else {

		return false;
	}
}

bool Rational::operator <= (const Rational& other) const {

	if (numerator <= other.numerator && denom <= other.denom) {

		return false;
	}
	else {

		return true;
	}
}

bool Rational::operator >= (const Rational& other) const {

	if (numerator >= other.numerator && denom >= other.denom) {

		return false;
	}
	else {

		return true;
	}
}

// Unary Operator
// Conversion Operator

Rational::operator string() const {

	string number;

	if (denom == 1 || denom == 0) {

		number = to_string(numerator);
		return number;
	}

	number = to_string(numerator) + "/" + to_string(denom);
	return number;
}

// returns 2/3 as “2/3”. If the denominator is 1 then only the numerator is returned, i.e. for 2/1 the operator shall return “2”

Rational::~Rational() {

} // destructor

ostream& operator<<(ostream& output, const Rational& obj) {

	return output;
}

// outputs the Rational

istream& operator>>(istream& input, Rational& obj) {

	cout << "Enter Numerator: " << endl;
	cin >> obj.numerator;

	cout << endl << "Enter Denominator: " << endl;
	cin >> obj.denom;

	cout << endl << endl;

	Simplify(obj.numerator, obj.denom);

	return input;
}