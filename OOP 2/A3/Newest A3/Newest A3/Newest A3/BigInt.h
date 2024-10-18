#include "pch.h"
#include <iostream>
using namespace std;

/*		Muneel Haider
		21i-0640
		Assignment 3		*/

class BigInt {

	string whole;
	unsigned long long number;

public:

	BigInt(int);

	BigInt(const string&);
	
	BigInt(const BigInt&);

	unsigned long long ConvertStringtoInt();

	// Binary Operators
	// Arithmetic Operators
	//BigInt operator+();
	//BigInt operator+(int val) const;
	//BigInt operator-(const BigInt& val) const;
	//BigInt operator-(int val) const;
	//BigInt operator*(const BigInt& val) const;

	//// Compound Assignment Operators
	//BigInt operator+=(const BigInt& rhs);
	//BigInt operator-=(const BigInt& rhs);
	//BigInt operator*=(const BigInt& rhs);
	
	// Logical Operators
	
	bool operator==(const BigInt& val) const;
	
	bool operator!=(const BigInt& val) const;
	
	bool operator<(const BigInt& val) const;
	
	bool operator<=(const BigInt& val) const;
	
	bool operator>(const BigInt& val) const;
	
	bool operator>=(const BigInt& val) const;

	//// Unary Operators
	//BigInt& operator++();  // Pre-increment Operator
	//BigInt operator++(int);  // Post-increment Operator
	//BigInt& operator--();  // Pre-decrement Operator
	//BigInt operator--( int ); // Post-decrement Operator

	friend ostream& operator<<(ostream& output, const BigInt& val);
	friend istream& operator>>(istream& input, BigInt& val);

	////Conversion Operator
	operator string() {

		return this->whole;
	}
	string BigInt::StringConverter(int);

};

BigInt::BigInt(int val = 0) {

	whole = StringConverter(val);
	number = 0;
	number = ConvertStringtoInt();
}

BigInt::BigInt(const string& text) {

	whole = text;
	number = 0;
	number = ConvertStringtoInt();
}

BigInt::BigInt(const BigInt& copy) {

	this->whole = copy.whole;
	number = 0;
	int size = whole.length();

	number += copy.whole[0] - 48;

	for (int i = 1; i < size; i++) {

		number *= 10;
		number += copy.whole[i] - 48;
	}
}

unsigned long long BigInt::ConvertStringtoInt() {

	int size = whole.length();

	number += whole[0] - 48;

	for (int i = 1; i < size; i++) {

		number *= 10;
		number += whole[i] - 48;
	}

	return number;
}

ostream& operator<<(ostream& output, const BigInt& val) {

	return output;
}

istream& operator>>(istream& input, BigInt& val) {

	input >> val.whole;

	return input;
}

bool BigInt::operator==(const BigInt& val) const {

	int size1 = this->whole.length();
	int size2 = val.whole.length();

	if (size1 > size2 || size1 < size2) {

		return false;
	}

	return true;
}

bool BigInt::operator!=(const BigInt & val) const {

	int size1 = this->whole.length();
	int size2 = val.whole.length();

	if (size1 > size2 || size1 < size2) {

		return true;
	}

	return false;
}

bool BigInt::operator<(const BigInt& val) const {

	int size1 = this->whole.length();
	int size2 = val.whole.length();

	if (size1 >= size2) {

		return false;
	}

	return true;
}

bool BigInt::operator<=(const BigInt& val) const {

	int size1 = this->whole.length();
	int size2 = val.whole.length();

	if (size1 > size2) {

		return false;
	}

	return true;
}

bool BigInt::operator>(const BigInt& val) const {

	int size1 = this->whole.length();
	int size2 = val.whole.length();

	if (size1 <= size2) {

		return false;
	}

	return true;
}

bool BigInt::operator>=(const BigInt& val) const {

	int size1 = this->whole.length();
	int size2 = val.whole.length();

	if (size1 < size2) {

		return false;
	}

	return true;
}

string BigInt::StringConverter(int value) {

	char result[20] = {};
	char lmao[20] = {};
	int temp = 0;
	int number = 0;
	int index = 0;
	int counter = 0;
	bool flag = false;

	while (value != 0 || index == 20) {

		temp = value % 10;
		value /= 10;
		result[index] = char(temp + 48);
		index++;
	}
	result[index] = '\0';

	counter = index - 1;

	for (int i = 0; i < index; i++) {

		lmao[i] = result[counter];
		counter--;
		temp = i;
	}
	lmao[temp + 1] = '\0';

	return lmao;
}