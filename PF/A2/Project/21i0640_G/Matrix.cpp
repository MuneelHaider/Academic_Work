#include <iostream>
#include "pch.h"
#include "Matrix.h"
using namespace std;

Matrix::Matrix() {

}

Matrix::Matrix(int n1, int n2, int n3, int n4, int row1, int col1) {

	row = row1;
	col = col1;

	matrix = new int* [row];
	for (int i = 0; i < row; i++) {

		matrix[i] = new int[col];
	}

	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[1][0] = n3;
	matrix[1][1] = n4;

	row = row1;
	col = col1;
}

Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row1,
	int col1) {

	row = row1;
	col = col1;

	matrix = new int* [row];
	for (int i = 0; i < row; i++) {

		matrix[i] = new int[col];
	}

	int counter = 0;
	int array[9] = { n1, n2, n3, n4, n5, n6, n7, n8, n9 };

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			matrix[i][j] = array[counter];
			counter++;
		}
	}

	row = 3;
	col = 3;
}

Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int
	n11, int n12, int n13, int n14, int n15, int n16, int row1, int col1) {

	row = row1;
	col = col1;

	matrix = new int* [row];
	for (int i = 0; i < row; i++) {

		matrix[i] = new int[col];
	}

	int counter = 0;
	int array[16] = { n1, n2, n3, n4,n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16 };

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			matrix[i][j] = array[counter];
			counter++;
		}
	}

	row = 4;
	col = 4;
}

Matrix::Matrix(const Matrix& m) {

	row = m.row;
	col = m.col;

	matrix = new int* [row];
	for (int i = 0; i < row; i++) {

		matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix::~Matrix() {

	delete[] matrix;
}

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

int Matrix::getCol() const {

	return col;
}

int Matrix::getRow() const {

	return row;
}

Matrix Matrix::Transpose() {

	Matrix Object(*this);

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			Object.matrix[j][i] = matrix[i][j];
		}
	}

	return Object;
}

Matrix Matrix::Add(Matrix) {

	Matrix obj;

	return obj;
}

Matrix Matrix::Subtract(Matrix) {

	Matrix obj;

	return obj;
}

Matrix Matrix::Multiply(Matrix) {

	Matrix obj;

	return obj;
}

int Matrix::FindkSmallest(int) {

	return 0;
}

int Matrix::FindkLargest(int) {

	return 0;
}

Matrix Matrix::merge(Matrix) {

	Matrix obj;

	return obj;
}