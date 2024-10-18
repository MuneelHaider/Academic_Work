#pragma once
#include <iostream>
using namespace std;

/*	Muneel Haider
	21i-0640
	Assignment 1	*/

void DisplayB(int** matrix, int rows, int cols) {

	// Displays given matrix

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << "\t" << *(*(matrix + i) + j);
		}

		cout << endl;
	}
}

int** FillB(int** matrix, int rows, int cols) {

	int random = 0;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			// Generates random number btw 0 - 9
			random = rand() % 10;
			random = rand() % 10;
			random = rand() % 10;

			*(*(matrix + i) + j) = random;
		}
	}

	return matrix;
}

int** NextCheck(int** matrix, int rows, int cols, int& score, bool& run, int& r, int& c) {

	while(run == true) {

		if (r == 0 && c == 0) {

			run = false;
			break;
		}

		else if (c == 0) {

			r--;
			score += *(*(matrix + r) + c);
			break;
		}

		else if (r == 0) {

			c--;
			score += *(*(matrix + r) + c);
			break;
		}

		else if ( matrix[r][c-1] < matrix[r-1][c]) {

			c--;
			score += *(*(matrix + r) + c);
			break;
		}

		else if( matrix[r-1][c] < matrix[r][c-1]) {

			r--;
			score += *(*(matrix + r) + c);
			break;
		}
	}

	return matrix;
}

int minCost(int**& matrix, int rows, int cols) {

	// Initializing variables
	int scoreB = *(*(matrix + rows - 1) + (cols - 1));
	int random = 0;
	int r = rows - 1;
	int c = cols - 1;
	bool run = true;

	DisplayB(matrix, rows, cols);

	while (run == true) {

		NextCheck(matrix, rows, cols, scoreB, run, r, c);
	}

	return scoreB;
}