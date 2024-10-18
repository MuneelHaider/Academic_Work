#pragma once
#include <iostream>
using namespace std;

template <class M>
class Container {

	M* values;
	int capacity;
	int counter;

public:

	Container(int c = 0) {

		capacity = c;
		counter = 0;
		values = new M[capacity];
	}

	bool isFull() {

		if (counter == capacity) {

			return true;
		}
		else {

			return false;
		}
	}

	void insert(M temp) {

		if (!isFull()) {

			values[counter] = temp;
			counter++;

			cout << "Entered Successfully!" << endl;
		}
		else {

			cout << "Capacity is full." << endl;
		}
	}

	bool search(M temp) {

		for (int i = 0; i < counter; i++) {

			if (values[i] == temp) {

				return true;
			}
		}

		return false;
	}

	void remove() {

		values[counter] = 0;
		counter--;
	}

	void print() {

		for (int i = 0; i < counter; i++) {

			cout << values[i] << endl;
		}
	}
};