#pragma once
#include <iostream>
using namespace std;

template<class T>
class List {

public:

	T* values;
	int capacity;
	int counter;

	List() {
	
		values = new T;
		capacity = 0;
		counter = 0;
	}

	List(int size) {

		values = new T[size];
		capacity = size;
		counter = 0;
	}

	bool insert(int number) {

		if (counter == capacity) {

			return false;
		}

		values[counter] = number;
		counter++;
	
		return true;
	}

	bool insertAt(T item, int index) {

		T temp;

		if (index < counter && counter < capacity) {

			// Sorting
			for (int i = capacity - 1; i >= index; i--) {

				values[i + 1] = values[i];
			}

			values[index] = item;

			return true;
		}
		else if (index >= counter && counter < capacity) {

			values[index] = item;

			return true;
		}

		return false;
	}

	bool insertAfter(T itemToBeInserted, T item) {

		if (counter == capacity) {

			return false;
		}

		for (int i = 0; i < counter; i++) {

			if (values[i] == item && i < counter) {

				for (int c = capacity; c > i + 1; c--) {

					values[c + 1] = values[c];
				}

				values[i + 1] = itemToBeInserted;
				counter++;

				return true;
			}
			else if (values[i] == item && i >= counter) {

				values[i + 1] = itemToBeInserted;
				counter++;

				return true;
			}
		}

		return false;
	}

	bool insertBefore(T itemToBeInserted, T item) {

		if (counter == capacity) {

			return false;
		}

		for (int i = 0; i < counter; i++) {

			if (values[i] == item) {

				for (int c = counter - 1; c > i - 1; c--) {

					values[c + 1] = values[c];
				}

				values[i] = itemToBeInserted;
				counter++;

				return true;
			}
		}

		return false;
	}

	void print() {

		for (int i = 0; i < capacity; i++) {

			cout << values[i] << endl;
		}
	}

	bool isEmpty() {

		if (counter == 0) {

			return true;
		}

		return false;
	}

	bool isFull() {

		if (counter == capacity) {

			return true;
		}

		return false;
	}

	void remove(T item) {

		for (int i = 0; i < counter; i++) {

			if (values[i] == item) {

				values[i] = 0;

				for (int c = i; c < counter; c++) {

					values[c] = values[c + 1];
				}

				counter--;
			}
		}
	}

	int search(T item) {

		for (int i = 0; i < counter; i++) {

			if (values[i] == item) {

				return i;
			}
		}

		return -1;
	}

	bool operator==(List& L) {

		if (capacity != L.capacity) {

			return false;
		}

		for (int i = 0; i < counter; i++) {

			if (values[i] != L.values[i]) {

				return false;
			}
		}

		return true;
	}

	void reverse() {

		T* ptr = new T[capacity];

		int i = 0;
		int j = counter - 1;

		for (i = 0; i < counter; i++) {

			ptr[i] = values[j];
			j--;
		}

		for (int i = 0; i < counter; i++) {

			values[i] = ptr[i];
		}
	}

	void removeBefore(T item) {

		for (int i = 0; i < counter; i++) {

			if (values[i] == item) {

				values[i - 1] = 0;

				for (int c = i - 1; c < counter; c++) {

					values[c] = values[c + 1];
				}

				counter--;
			}
		}
	}

	void removeAfter(T item) {

		for (int i = 0; i < counter; i++) {

			if (values[i] == item) {

				values[i + 1] = 0;

				for (int c = i + 1; c < counter; c++) {

					values[c] = values[c + 1];
				}

				counter--;
			}
		}
	}

};