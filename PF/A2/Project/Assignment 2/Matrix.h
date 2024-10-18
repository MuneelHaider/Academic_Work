#pragma once

class Matrix {

	int row;
	int col;
	int** matrix;

public:

	Matrix() {

	}

	Matrix(int n1, int n2, int n3, int n4, int row1 = 2, int col1 = 2) {

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

	Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row1 = 3,
		int col1 = 3) {

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

	Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int
		n11, int n12, int n13, int n14, int n15, int n16, int row1 = 4, int col1 = 4) {

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

	Matrix(const Matrix& m) {

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

	~Matrix() {

	}

	int getRow();
	int getCol();
	int getValue(int row, int col);
	void setValue(int row, int col, int value);
	int Total();
	double Average();
	int RowTotal(int row);
	int ColumnTotal(int col);
	int HighestInRow(int row);
	int LowestInRow(int row);
	int LeftDiagonalTotal();
	int RightDiagonalTotal();

	Matrix Transpose() {

		Matrix Object(*this);

		for (int i = 0; i < row; i++) {

			for (int j = 0; j < col; j++) {

				Object.matrix[j][i] = matrix[i][j];
			}
		}

		return Object;
	}
};