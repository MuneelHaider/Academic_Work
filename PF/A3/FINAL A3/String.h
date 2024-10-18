/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 2			*/

#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class String {

	int length;
	char* s = new char[100];

public:
	// provide definitions of following functions
	String();
	// default constructor
	String(const char* str);
	// initializes the string with constant c-string
	String(const String&);
	// copy constructor to initialize the string from the existing string
	String(const string& obj);
	String(int x); // initializes a string of predefined size
	char& operator[](int i);
	// returns the character at index [x]
	const char operator[](int i) const;
	// returns the character at index [x]
	// Arithmetic Operators
	String operator+(const String& str);
	// appends a String at the end of the String
	String operator+(const char& str);
	// appends a char at the end of the String
	String operator+(char*& str);
	// appends a String at the end of the String
	String operator-(const String& substr);
	//removes the substr from the String
	String operator-(const string& substr);
	//removes the substr from the String
	// Assignment Operators
	String operator=(const String&);
	// copies one String to another
	String operator=(char*);
	// copies one c-string to another
	String operator=(const string&);
	// copies one string to another
	// Logical Operators
	bool operator==(const String&) const;
	// returns true if two Strings are equal
	bool operator==(const string&) const;
	// returns true if the string is equal to the String
	bool operator==(char*) const;
	// returns true if the c-string is equal to the String

	// Unary Operators
	// Boolean Not Operator
	bool operator!();
	// returns true if the String is empty
	// Function-Call Operators
	int operator()(char) const; // returns the index of the character being searched
	int operator()(const String&) const; // returns the index of the String being searched
	int operator()(const string&) const; // returns the index of the string being searched
	int operator()(char*) const; // returns the index of the c-string being searched
	// Conversion Operator
	operator int() const; // returns the length of string
//	~String(); // destructor

	friend ostream& operator<<(ostream& output, const String&); // outputs the string
	friend istream& operator>>(istream& input, String&); // inputs the string

};

// Operator Overloading as Non-Member Functions
// Stream Insertion and Extraction Operators
ostream& operator<<(ostream& output, const String&); // outputs the string
istream& operator>>(istream& input, String&); // inputs the string

