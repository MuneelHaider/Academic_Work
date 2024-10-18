#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/********************* TASK 1 **********************/

int** transposeMatrix(int arr1[][2], int row, int col) {

	int** transpose = new int* [row];
	for (int i = 0; i < row; i++) {

		transpose[i] = new int[col];
	}

	for (int i = 0; i < row; ++i) {

		for (int j = 0; j < col; ++j) {

			transpose[j][i] = arr1[i][j];
		}
	}

	return transpose;
}

int* colSum(int arr[][4], int row, int col) {

	int* sum = new int[col];

	for (int i = 0; i < row; i++) {

		sum[i] = 0;

		for (int j = 0; j < col; j++) {

			sum[i] += arr[j][i];
		}
	}

	return sum;
}

int* rowSum(int arr[][4], int row, int col) {

	int* sum = new int[row];

	for (int i = 0; i < row; i++) {

		sum[i] = 0;

		for (int j = 0; j < col; j++) {

			sum[i] += arr[i][j];
		}
	}

	return sum;
}

int arraySum(int arr[][5], int row, int col) {

	int sum = 0;
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			sum += arr[i][j];
		}
	}

	return sum;
}

/********************* TASK 2 *********************/

int** matrixSum(int arr[][3], int arr1[][3], int row, int col) {

	int sum = 0;
	int** ex = new int* [row];
	for (int i = 0; i < row; i++) {

		ex[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			ex[i][j] = arr[i][j] + arr1[i][j];
		}
	}

	return ex;
}

int** multiplyMatrix(int arr[][2], int arr1[][2], int row, int col) {

	int sum = 0;
	int** ex = new int* [row];
	for (int i = 0; i < row; i++) {

		ex[i] = new int[col];
	}

	for (int i = 0; i < row; ++i) {
		
		for (int j = 0; j < col; ++j) {
		
			for (int k = 0; k < col; ++k) {

				ex[i][j] = arr[i][k] * arr1[k][j];
			}
		}
	}

	return ex;
}

/********************* TASK 3 *********************/

int leftDiagonalSum(int arr1[][4], int row, int col) {

	int sum = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
				sum = sum + arr1[i][j];
		}
	}

	return sum;
}

int rightDiagonalSum(int arr1[][4], int row, int col) {

	int sum = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i + j) == (col - 1))
				sum = sum + arr1[i][j];
		}
	}

	return sum;
}

/********************* TASK 4 *********************/

int* displayMiddleRow(int arr[][5], int row) {

	int* Arr1 = new int[row];
	
	for (int i = 0; i < row; i++) {

		Arr1[i] = arr[2][i];
	
		cout << Arr1[i] << "\t";
	}

	return Arr1;
}

int* displayMiddleCol(int arr[][5], int col) {

	int* Arr1 = new int[col];

	for (int i = 0; i < col; i++) {

		Arr1[i] = arr[i][2];

		cout << Arr1[i] << "\t";
	}

	return Arr1;
}

/********************* TASK 5 *********************/

const char* Name = "TASK5.txt";

class Task5 {

public:

	int array[5][5];

	Task5() {

		for (int i = 0; i < 5; i++) {

			for (int j = 0; j < 5; j++) {

				array[i][j] = 0;
			}
		}
	}

	void InputElements() {

		for (int i = 0; i < 5; i++) {

			for (int j = 0; j < 5; j++) {

				cout << "Row: " << i << endl;
				cout << "Col: " << j << endl;
				cin >> array[i][j];
			}
		}
	}

	void DisplayMatrix() {

		for (int i = 0; i < 5; i++) {

			for (int j = 0; j < 5; j++) {

				cout << array[i][j] << endl;
			}

			cout << endl;
		}
	}

	void Reader(Task5& obj) {

		int lol;
		fstream myFile(Name);

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				myFile >> obj.array[i][j];

			}
			cout << endl;
		}
	}
};