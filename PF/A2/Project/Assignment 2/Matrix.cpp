#include <iostream>
#include "pch.h"
#include "Matrix.h"
using namespace std;



int Matrix::RightDiagonalTotal() {

	int sum = 0;
	int r = 0;
	int c = col - 1;

	while (c != -1) {

		sum += matrix[r++][c--];
	}

	return sum;
}

int Matrix::LeftDiagonalTotal() {

	int sum = 0;

	for (int i = 0; i < row; i++) {

		sum += matrix[0 + i][0 + i];
	}

	return sum;
}

int Matrix::LowestInRow(int row) {

	int min = matrix[row][0];

	for (int i = 0; i < col; i++) {

		if (matrix[row][i] < min) {

			min = matrix[row][i];
		}
	}

	return min;
}

int Matrix::HighestInRow(int row) {

	int max = matrix[row][0];

	for (int i = 0; i < col; i++) {

		if (matrix[row][i] > max) {

			max = matrix[row][i];
		}
	}

	return max;
}

int Matrix::ColumnTotal(int col) {

	int sum = 0;

	for (int i = 0; i < row; i++) {

		sum += matrix[i][col];
	}

	return sum;
}

int Matrix::RowTotal(int row) {

	int sum = 0;

	for (int j = 0; j < col; j++) {

		sum += matrix[row][j];
	}

	return sum;
}

double Matrix::Average() {

	double sum = 0, counter = 0;

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			sum += matrix[i][j];
			counter++;
		}
	}

	double average = sum / counter;

	return average;
}

int Matrix::Total() {

	int sum = 0;

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			sum += matrix[i][j];
		}
	}
	
	return sum;
}

void Matrix::setValue(int row, int col, int value) {

	matrix[row][col] = value;
}

int Matrix::getValue(int row, int col) {

	return matrix[row][col];
}

int Matrix::getCol() {

	return col;
}

int Matrix::getRow() {

	return row;
}