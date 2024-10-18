#include "pch.h"
#include <iostream>
using namespace std;

/*		Muneel Haider
		21i-0640
		Assignment 3		*/

class Polynomial {

	int degree;
	string poly;

public:
	
	Polynomial(); // a default constructor
	Polynomial(int); // a parameterized constructor, received the highest degree of polynomial
	Polynomial(const Polynomial &); // a copy constructor

	// Binary Operators
	// Assignment Operator
	Polynomial operator=(const Polynomial& rhs); //assigns (copies) the rhs Polynomial to "this" Polynomial
	// Arithmetic Operators
	Polynomial operator+(const Polynomial&); // adds two Polynomials and returns the result
	Polynomial operator-(const Polynomial&); // subtracts two Polynomials and returns the result
	//// Compound Assignment Operators
	void operator+=(const Polynomial&); // adds two Polynomials
	void operator-=(const Polynomial&); // subtracts two Polynomials
	//// Logical Operator
	bool operator==(const Polynomial&); // compares and returns true if equal

	//// Conversion Operator
	friend ostream& operator<<(ostream& output, const Polynomial&);
	friend istream& operator>>(istream& input, Polynomial& obj);
	operator string() const; // returns the value of the Polynomial as a string like “4x^3 + 3x + 2"
	~Polynomial() {}
};