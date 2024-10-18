#include "pch.h"
#include "Array.h"
#include <iostream>
using namespace std;

Array::Array() {

	*array = { 0 };
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

	for (int j = 0; j < length; i++) {

		if (array[i] == array[j]) {

			return array[j];
		}
	}
}
// returns the integer at index [i] after checking the out of range error

int& Array::operator[](int i)const {

	for (int j = 0; j < length; i++) {

		if (array[i] == array[j]) {

			return array[j];
		}
	}
}

const Array& Array::operator=(const Array& obj) {

	length = obj.length;

	for (int i = 0; i < length + 1; i++) {

		array[i] = obj.array[i];
	}

	return obj;
} 
//copy the array

Array Array::operator+(const Array& obj) {

	int i = 0;
	while(i < length) {

		array[i] += obj.array[i];
		i++;
	}

	cout << endl << endl << "ARRAY[1] " << array[1] << endl << endl;

	return *this;
} 
//adds two Array

Array Array::operator-(const Array& obj) {

	length = obj.length;

	for (int i = 0; i < obj.length; i++) {

		array[i] -= obj.array[i];
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

	if (length == obj.length) {

		for (int i = 0; i < length; i++) {

			array[i] += obj.array[i];
		}
	}
}
// adds two Array

void Array::operator-=(const Array& obj) {

	if (length == obj.length) {

		for (int i = 0; i < length; i++) {

			array[i] -= array[i];
		}
	}
}
// subtracts two Array

int Array::operator()(int idx, int val) {

	bool flag = false;
	bool erase = false;
	int temp = 0;

	for (int i = 0; i < length; i++) {

		if (array[idx] == array[i]) {

			array[idx] -= val;
			flag = true;

			if (array[idx] <= 0) {

				erase = true;
			}
		}
 	}

	if (flag == true) {

		if (erase == true) {

			for (int i = idx; i < length; i++) {

				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}

			length--;
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