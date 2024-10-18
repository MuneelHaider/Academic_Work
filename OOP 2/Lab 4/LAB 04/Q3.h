#pragma once
#include <iostream>
using namespace std;

int*** createArray3(int rows, int cols) {

	// Creating 3D array
	int*** array = new int** [rows];
	for (int i = 0; i < rows; i++) {

		// Makes 2D
		array[i] = new int* [cols];

		for (int j = 0; j < cols; j++) {

			// Makes 3D
			array[i][j] = new int[2];
			array[i][j][0] = 0;
		}
	}

	int counter = 0;
	// Filling Array
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			for (int k = 0; k < 2; k++) {

				*(*(*(array + i) + j) + k) = counter++;
			}
		}
	}

	return array;
}

int*** define3DArray(int rows, int cols) {

	// Creating 3D array
	int*** array = createArray3(rows, cols);

	return array;
}

int SUM3D(int rows, int cols) {

	int*** array = define3DArray(rows, cols);
	int sum = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < 2; k++) {

				sum += array[i][j][k];
			}

		}
	}

	return sum;
}

float findAverageOf3DArray(int*** array, int rows, int cols) {

	float sum = 0;
	float average = 0;
	float counter = 0;

	array = define3DArray(rows, cols);
	sum = SUM3D(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < 2; k++) {

				counter++;
			}

		}
	}

	average = sum / counter;

	return average;
}