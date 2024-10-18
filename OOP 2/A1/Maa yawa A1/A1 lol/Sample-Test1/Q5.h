#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

/*	Muneel Haider
	21i-0640
	Assignment 1	*/

int maximum(int* ptr, int size) {

	int max = 0;
	int counter = 0;

	while (counter < size) {

		if (ptr[counter] > max) {

			max = ptr[counter];
		}

		counter++;
	}

	return max;
}

void swap(int* n1, int* n2) {

	int* number_1 = new int;
	int* number_2 = new int;
	int* temp = new int;

	number_1 = n1;
	number_2 = n2;

	*temp = *number_1;
	*number_1 = *number_2;
	*number_2 = *temp;
}

char* reverse(char* ptr) {

	int size = 0;
	for (int i = 0; ptr[i] != '\0'; i++) {

		size++;
	}

	int counter = 0;
	char* str = new char[size];

	for (int i = 0; i < size; i++) {

		str[i] = ptr[i];
	}

	for (int i = size - 1; i >= 0; i--) {

		ptr[counter] = str[i];
		counter++;
	}

	return ptr;
}

int* merge(int* arr1, int* arr2, int size_1, int size_2) {

	int* array = new int[size_1 + size_2];
	
	for (int i = 0; i < size_1; i++) {

		array[i] = arr1[i];
	}

	for (int i = 0; i < size_2; i++) {

		array[size_1 + i] = arr2[i];
	}

	return array;
}

int countEven(int* array, int size) {

	int total = 0;

	for (int i = 0; i < size; i++) {

		if (array[i] % 2 == 0) {

			total++;
		}
	}

	return total;
}

bool compare(char* array, char letter) {

	if (*array == letter) {

		return true;
	}
	else {

		return false;
	}
}

void Populateplanets(int* array, int size) {

	int random = 0;
	array = new int[size];

	for (int i = 0; i < size; i++) {

		random = rand() % 10;
		array[i] = random;
		cout << *(array + i) << endl;
	}
}