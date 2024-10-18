#pragma once
#include <iostream>
using namespace std;

template <typename M>
void Sorter(M* array, int size, int index) {

	M temp;

	for (int i = index; i < size; i++) {

		temp = array[i];
		array[i] = array[i + 1];
		array[i + 1] = temp;
	}
}

template <typename M>
int Counter(M* array, int size) {

	int counter = 0;

	for (int i = 0; i < size; i++) {

		if (array[i] == 0) {

			counter++;
		}
	}

	return counter;
}

template <typename M>
void ArrayFinder(M* num1, M* num2, int size) {

	for (int i = 0; i < size; i++) {
	
		for (int j = 0; j < size; j++) {

			if (num1[i] == num2[j]) {
				
				cout << num1[i] << endl;

				num1[i] = 0;
				num2[j] = 0;

				Sorter(num1, size, i);
				Sorter(num2, size, j);
			}
		}
	}
}