#pragma once

class Matrix {

	int row;
	int col;
	int** matrix;

public:

	Matrix();
	Matrix(int n1, int n2, int n3, int n4, int row1 = 2, int col1 = 2);
	Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row1 = 3,
		int col1 = 3);
	Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int
		n11, int n12, int n13, int n14, int n15, int n16, int row1 = 4, int col1 = 4);
	Matrix(const Matrix& m);
	~Matrix();

	int getRow() const;
	int getCol() const;
	int getValue(int, int);
	void setValue(int, int, int);
	int Total();
	double Average();
	int RowTotal(int);
	int ColumnTotal(int);
	int HighestInRow(int);
	int LowestInRow(int);
	Matrix Transpose();
	int LeftDiagonalTotal();
	int RightDiagonalTotal();
	Matrix Add(Matrix);
	Matrix Subtract(Matrix);
	Matrix Multiply(Matrix);
	int FindkSmallest(int);
	int FindkLargest(int);
	Matrix merge(Matrix);
};