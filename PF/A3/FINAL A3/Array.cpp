/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 3			*/

#include "pch.h"
#include "Array.h"
#include <iostream>
using namespace std;

Array::Array() {

	*array = NULL;
	length = 0;
} 
// a default constructor

Array::Array(int size) {

	length = size;
	

	for (int i = 0; i < length; i++) {

		*(array + i) = 0;
	}
}
// a parametrized constructor initializing an Array of predefined size

Array::Array(int* arr, int size) {

	length = size;
	
	for (int i = 0; i < length; i++) {

		array[i] = arr[i];
	}
} 
// initializes the Array with a existing Array

Array::Array(const Array& obj) {
	
	length = obj.length;

	for (int i = 0; i < length + 1; i++) {

		array[i] = obj.array[i];
	}
} 
// copy constructor

int& Array::operator[](int i) {

	if(i > length || i <= -1) {
	
		exit(-1);
	}
	else {

		return array[i];
	}
}
// returns the integer at index [i] after checking the out of range error

int& Array::operator[](int i)const {

	if (i > length || i <= -1) {

		return array[0];
	}
	else {

		return array[i];
	}
}

const Array& Array::operator=(const Array& obj) {

	length = obj.length;

	for (int i = 0; i < length; i++) {

		array[i] = obj.array[i];
	}

	return *this;
} 
//copy the array

Array Array::operator+(const Array& obj) {

	length = obj.length;

	for (int i = 0; i < length; i++) {

		array[i] = array[i] + obj.array[i];
	}

	return *this;
} 
//adds two Array

Array Array::operator-(const Array& obj) {

	length = obj.length;

	for (int i = 0; i < obj.length; i++) {
	
		array[i] = array[i] - obj.array[i];
	}

	return *this;
}
//subtracts two Array

Array Array::operator++() {

	for (int i = 0; i < length; i++) {

		++array[i];
	}

	return *this;
}
// adds one to each element of Array

Array Array::operator++(int) {

	for (int i = 0; i < length; i++) {

		array[i]++;
	}

	return *this;
}
// adds one to each element of Array

Array& Array::operator--(int) {

	for (int i = 0; i < length; i++) {

		array[i]--;
	}

	return *this;
}
// subtracts one from each element of Array

bool Array::operator==(const Array& obj)const {

	if (length == obj.length) {

		for (int i = 0; i < length; i++) {

			if (array[i] != obj.array[i]) {

				return false;
			}
		}

		return true;
	}
	else {

		return false;
	}
}
// returns true if two arrays are same

bool Array::operator!() {

	if (length == 0) {

		return true;
	}
	else if (*(array) == NULL) {

		return true;
	}
	else {

		return false;
	}
} 
// returns true if the Array is empty

void Array::operator+=(const Array& obj) {

	for (int i = 0; i < obj.length; i++) {

		array[i] += obj.array[i];
	}
}
// adds two Array

void Array::operator-=(const Array& obj) {

	for (int i = 0; i < obj.length; i++) {

		array[i] -= obj.array[i];
	}
}
// subtracts two Array

int Array::operator()(int idx, int val) {

	if (array[idx] == val) {

		length -= 1;
		int* temp = new int[length];

		for (int i = 0; i < length; i++) {

			if (idx > i) {

				temp[i] = array[i];
			}
			else {

				temp[i] = array[i + 1];
			}
		}

		array = new int[length];

		for (int i = 0; i < length; i++) {

			array[i] = temp[i];
		}

		return 1;
	}

	else {

		return -1;
	}
}
// erases the value val at idx. Returns 1 for a successful deletion and -1 if idx does not exist or is invalid. Shift the elements after idx to the left.

Array::~Array() {

	delete[] array;
} 
// destructor...

ostream& operator<<(ostream& input, const Array&) {

	return input;
}

istream& operator>>(istream& output, Array& obj) {

	cin >> obj.length;
	for (int i = 0; i < obj.length; i++) {

		cin >> obj.array[i];
	}

	return output;
}