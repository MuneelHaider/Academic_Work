#pragma once
#include <iostream>
using namespace std;

class Vector {

	int* array = new int[3];
	int length;

public:

	Vector(int l = 3) {

		length = l;
	}

	int* getArray() {

		return array;
	}
	void equateArray(int* arr) {

		array = arr;
	}

	void setArray(int x = 0) {

		for (int i = 0; i < 3; i++) {

			array[i] = x;
		}
	}

	void printArray() {

		cout << endl << endl;

		for (int i = 0; i < 3; i++) {

			cout << array[i] << endl;
		}
	}

	int setLength(int l) {

		length = l;
	}
	int getLength() {

		return length;
	}



	Vector operator+(Vector V1);
	Vector operator-(Vector V1);
};

Vector Vector::operator+(Vector V1) {

	for (int i = 0; i < 3; i++) {

		this->array[i] += V1.array[i];
 	}

	return *this;
}

Vector Vector::operator-(Vector V1) {

	for (int i = 0; i < 3; i++) {

		this->array[i] -= V1.array[i];
	}

	return *this;
}