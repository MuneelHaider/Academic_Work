#pragma once

/*	Muneel Haider
	21i-0640
	Task 2			*/

#include<iostream>
using namespace std;

class Vector {

	int length = 3;
	int* array = new int[length];

public:

	Vector() {

		length = 3;
		array = new int[length];
	}
	Vector(int* a) {

		int* temp = new int[3];
		for (int i = 0; i < 3; i++) {

			temp[i] = a[i];
			this->array[i] = temp[i];
		}
	}

	int getLength() {

		return length;
	}
	void setLength(int l) {

		length = l;
	}

	int* getArray() {

		return array;
	}
	void setArray(int* obj) {

		for (int i = 0; i < 3; i++) {

			this->array[i] = obj[i];
		}
	}

	Vector(Vector& obj) {
		
		int l = 0;
		int* s = new int[3];	// Created new array dynamically

		l = obj.length;			// Using another variable for deep copy
		length = l;

		for (int i = 0; i < 3; i++) {

			s[i] = obj.array[i];	// Since new memory has been allocated, The this-> array 
			this->array[i] = s[i];	// will have saved values in a different memory address
		}
	}

	int* addVectors(Vector V1, Vector V2) {

		int* temp = new int[3];

		for (int i = 0; i < 3; i++) {

			temp[i] = V1.array[i] + V2.array[i];
		}

		return temp;
	}

	int* subVectors(Vector V1, Vector V2) {

		int* temp = new int[3];

		for (int i = 0; i < 3; i++) {

			temp[i] = V1.array[i] - V2.array[i];
		}

		return temp;
	}
};