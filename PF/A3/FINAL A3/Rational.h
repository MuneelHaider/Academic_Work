/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 1			*/

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
#include <string>
using namespace std;

class Rational {

	int numerator;
	int denom;

public:
	Rational();
	Rational(int, int);
	Rational(const Rational &copy);// copy constructor to initialize the Rational form existing Rational //object
	// Binary Operators
	// Assignment Operator
	Rational operator = (const Rational &x);
	// Arithmetic Operators
	Rational operator+(const Rational &x) const;
	Rational operator-(const Rational &x) const;
	Rational operator*(const Rational &x) const;
	Rational operator/(const Rational &x) const;
	// Compound Arithmetic Operators
	Rational operator += (const Rational &x);
	Rational operator -= (const Rational &x);
	Rational operator *= (const Rational &x);
	Rational operator /= (const Rational &x);
	// Logical Operators
	bool operator == (const Rational & other) const;
	bool operator < (const Rational & other) const;
	bool operator > (const Rational & other) const;
	bool operator <= (const Rational & other) const;
	bool operator >= (const Rational & other) const;

	// Unary Operator
	// Conversion Operator
	operator string() const; // returns 2/3 as “2/3”. If the denominator is 1 then only the numerator is returned, i.e. for 2/1 the operator shall return “2”
	~Rational(); // destructor

	friend ostream& operator<<(ostream& output, const Rational&);
	friend istream& operator>>(istream& input, Rational&);
};



// inputs the Rational


#endif /* RATIONAL_H_ */
