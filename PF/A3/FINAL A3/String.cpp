/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 2			*/

#include "pch.h"
#include "String.h"
#include <iostream>
#include <string>
#include "String.h"
using namespace std;

String::String() {

	length = 0;
}
// default constructor

String::String(const char* str) {

	int l2 = 0;

	for (int i = 0; *(str + i) != '\0'; i++) {

		l2++;
	}

	length = l2;

	for (int i = 0; i < length; i++) {

		s[i] = str[i];
	}

	s[length] = '\0';
}
// initializes the string with constant c-string

String::String(const String& str) {

	length = str.length;

	for (int i = 0; i < length + 1; i++) {

		s[i] = str.s[i];

	}

	s[length] = '\0';
}

// copy constructor to initialize the string from the existing string

String::String(int x) {

	length = x;

	for (int i = 0; i < length; i++) {

		s[i] = '0';
	}
	s[length] = '\0';

}

// initializes a string of predefined size

char& String::operator[](int i) {

	return s[i];
}

// returns the character at index [x]

const char String::operator[](int i) const {

	return s[i];
}

// returns the character at index [x]

// Arithmetic Operators

String String::operator+(const String& str) {

	for (int i = 0; i < str.length; i++) {

		s[length] = str.s[i];
		length++;
	}

	s[length] = '\0';

	return *this;
}

// appends a String at the end of the String

String String::operator+(const char& str) {

	String result(*this);

	result.s[result.length++] = str;
	result.s[result.length] = '\0';

	return result;
}

// appends a char at the end of the String

String String::operator+(char*& str) {

	String result;
	result.s = this->s;
	result.length = this->length;

	int l2 = 0;

	for (int i = 0; *(str + i) != '\0'; i++) {

		l2++;
	}

	result.length += l2;

	for (int i = 0; i < l2; i++) {

		result.s[length + i] = *(str + i);
	}

	return result;
}

// appends a string at the end of the String

String String::operator-(const String& substr) {

	String result = *this;
	String final = *this;

	int index = result(substr);
	int l2 = strlen(substr.s);
	int i = 0, j = 0;

	while (this->s[i] != '\0' && substr.s[i] != '\0') {

		if (s[i] == s[index]) {

			i += l2;
			index = -1;
		}

		final.s[j] = s[i];
		j++;
		i++;
	}

	final.s[j] = '\0';

	return final;
}

//removes the substr from the String

String String::operator-(const string& substr) {

	char* string2;
	int point = substr.length();

	string2 = strstr(s, substr.c_str());

	if (string2) {

		int newlength = length - point;
		int index = string2 - s;
		String newstr(newlength);

		for (int i = 0; i < index; i++) {

			newstr.s[i] = s[i];
		}

		int index2 = length - point - index;

		for (int i = index; i <= index + index2; i++) {

			newstr.s[i] = s[i + point];
		}

		length = newlength;
		s = newstr.s;
	}

	return *this;
}

//removes the substr from the String

// Assignment Operators

String String::operator=(const String& string) {

	length = string.length;

	for (int i = 0; string.s[i] != '\0'; i++) {

		s[i] = string.s[i];
	}

	return *this;
}

// copies one String to another

String String::operator=(char* str) {

	length = strlen(str);

	for (int i = 0; str[i] != '\0'; i++) {

		s[i] = str[i];
	}

	return *this;
}

// copies one c-string to another

String String::operator=(const string& str) {

	length = str.length();

	for (int i = 0; i < length; i++) {

		s[i] = str[i];
	}

	return *this;
}

// copies one string to another

// Logical Operators

bool String::operator==(const String& string) const {

	if (length == string.length) {

		for (int i = 0; i < length; i++) {

			if (s[i] != string.s[i]) {

				return false;
			}
		}

		return true;
	}
	else {

		return false;
	}
}

// returns true if two Strings are equal

bool String::operator==(const string& str) const {

	int length2 = str.length();

	if (length == length2) {

		for (int i = 0; i < length; i++) {

			if (s[i] != str[i]) {

				return false;
			}
		}

		return true;
	}
	else {

		return false;
	}
}

// returns true if the string is equal to the String

bool String::operator==(char* str) const {

	if (length == strlen(str)) {

		for (int i = 0; i < length; i++) {

			if (s[i] != str[i]) {

				return false;
			}
		}

		return true;
	}
	else {

		return false;
	}
}

// returns true if the c-string is equal to the String


// Unary Operators
// Boolean Not Operator

bool String::operator!() {

	if (*this->s == '\0') {

		return true;
	}
	else {

		return false;
	}
}

// returns true if the String is empty

// Function-Call Operators

int String::operator()(char str) const {

	for (int i = 0; *(s + i) != '\0'; i++) {

		if (*(s + i) == str) {

			return i;
		}
	}

	return 0;
}

// returns the index of the character being searched

int String::operator()(const String& string) const {

	int index = 0;
	int c = 0;
	int counter = 0;

	int i = 0, i2 = 0;

	while (i < string.length) {

		i2 = 0;
		c = 0;

		if (s[i] == string.s[0]) {

			i++;
			i2++;
			while (s[i] == string.s[i2]) {

				i2++;

			}

		}

		i++;
	}
	return i;
}

// returns the index of the String being searched

int String::operator()(const string& str) const {

	int index = 0;
	int c = 0;
	int counter = 0;

	int i = 0, i2 = 0;

	while (i < str.length()) {

		i2 = 0;
		c = 0;

		if (s[i] == str[0]) {

			i++;
			i2++;
			while (s[i] == str[i2]) {

				i2++;

			}

		}

		i++;
	}
	return i;
}

// returns the index of the string being searched

int String::operator()(char* str) const {

	int index = 0;
	int c = 0;
	int counter = 0;

	int i = 0, i2 = 0;

	int size = 0;

	while (*(str + i) != '/0') {

		size++;

	}

	while (i < size) {

		i2 = 0;
		c = 0;

		if (s[i] == str[0]) {

			i++;
			i2++;
			while (s[i] == str[i2]) {

				i2++;

			}

		}

		i++;
	}
	return i;
}


// returns the index of the c-string being searched

// Conversion Operator

String::operator int() const {

	return length;
}

// returns the length of string

//String::~String() {
//
//	/*delete[] s;*/
//}

// destructor

// Operator Overloading as Non-Member Functions
// Stream Insertion and Extraction Operators

ostream& operator<<(ostream& output, const String& str) {

	return output;
}

// outputs the string

istream& operator>>(istream& input, String& str) {

	input >> str;

	return input;
}

// inputs the string

