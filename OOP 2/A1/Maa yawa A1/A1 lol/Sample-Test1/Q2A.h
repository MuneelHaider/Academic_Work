#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

/*	Muneel Haider
	21i-0640
	Assignment 1	*/

void Display(int** matrix, int rows, int cols) {

	// Displays the given matrix

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << "\t" << *(*(matrix + i) + j);
		}

		cout << endl;
	}
}

int** Fill(int** matrix, int rows, int cols) {

	int random = 0;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			// Generates random number btw 0 - 6
			random = rand() % 6;
			random = rand() % 6;
			random = rand() % 6;

			// For 1
			if (random == 0 || random == 3 || random == 4) {

				*(*(matrix + i) + j) = 1;
			}

			// For 0
			else if (random == 1) {

				*(*(matrix + i) + j) = 0;
			}

			// For -1
			else if (random == 2 || random == 5) {

				*(*(matrix + i) + j) = -1;
			}
		}
	}

	*(*(matrix + 0) + 0) = 1;

	return matrix;
}

int** EvenCheck(int** matrix, int rows, int cols, int& score, bool& run, int& r, int& c) {

	bool loop = true;

	for (int j = c; j < cols && loop == true; j++) {

		// Checks on right side
		if (*(*(matrix + r) + (j + 1)) == 1) {

			score++;
			c++;
		}

		else if(*(*(matrix + r) + (j + 1)) == 0) {

			c++;
		}

		// Check finds -1
		else if (*(*(matrix + r) + (j + 1)) == -1 || c == 0 || c == 4) {

			loop = false;

			// Checking in next row
			if (*(*(matrix + r + 1) + j) == 1) {

				score++;
				r++;
			}

			// Proceeds to next row without increasing score
			else if (*(*(matrix + r + 1) + j) == 0) {

				r++;
			}

			// Next row also has -1, terminate process
			else if (*(*(matrix + r + 1) + j) == -1 || r == rows) {

				run = false;
			}

			else {

				run = false;
			}

			break;
		}
	}

	return matrix;
}

int** OddCheck(int** matrix, int rows, int cols, int& score, bool& run, int& r, int& c) {

	for (int j = c; j >= 0; j--) {

		// Checks on left side
		if (*(*(matrix + r) + (j - 1)) == 1) {

			score++;
			c--;
		}

		else if (*(*(matrix + r) + (j - 1)) == 0) {

			c--;
		}

		// Check finds -1
		else if (*(*(matrix + r) + (j - 1)) == -1 || c == 0 || c == 4) {

			// Checking in next row
			if (*(*(matrix + r + 1) + j) == 1) {

				score++;
				r++;
			}

			// Proceeds to next row without increasing score
			else if (*(*(matrix + r + 1) + j) == 0) {

				r++;
			}

			// Next row also has -1, terminate process
			else if (*(*(matrix + r + 1) + j) == -1 || r == rows) {

				run = false;
			}

			else {

				run = false;
			}

			break;
		}
	}

	return matrix;
}

int maxScore(int**& matrix, int rows, int cols) {

	// Initializing Variables
	int score = 1;
	int random = 0;
	int r = 0;
	int c = 0;
	bool run = true;
	
	// Displays the filled matrix
	Display(matrix, rows, cols);

	// Runs the entire process until the condition is met
	while (run == true) {

		// Checks even rows
		matrix = EvenCheck(matrix, rows, cols, score, run, r, c);
		
		// Checks odd rows
		matrix = OddCheck(matrix, rows, cols, score, run, r, c);
	}

	return score;
}