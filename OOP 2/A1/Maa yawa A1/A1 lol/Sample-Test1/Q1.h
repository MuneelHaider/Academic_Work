#pragma once
#include <iostream>
using namespace std;

/*	Muneel Haider	
	21i-0640		
	Assignment 1	*/

void Display(char** rows, bool& run, int Num_of_rows) {

	// To print out the seating arrangement
	int counter = 0;

	// Displaying seating arrangement
	for (int i = 0; i < Num_of_rows; i++) {

		for (int j = 0; j < 5; j++) {

			cout << rows[i][j];
			counter++;

			if (counter == 5) {

				counter = 0;
				cout << endl;
			}
		}
	}
}

bool checkFull(char** rows, bool& run, int Num_of_rows) {

	// Checking whether seats are full
	bool check = false;

	for (int i = 0; i < Num_of_rows; i++) {

		for (int j = 0; j < 5; j++) {

			if (rows[i][j + 1] != 'X') {

				check = true;
			}
		}
	}

	// Checking
	for (int i = 0; i < Num_of_rows; i++) {

		for (int j = 0; j < 5; j++) {

			if (check == false) {

				cout << "All seats of the vehicle are now full. No seats are available.\nPlease try again later.\n";

				check = false;
			}
		}
	}

	// returns true if seats are available
	return check;
}

char** InputSeats(char** rows, bool& run, int Num_of_rows) {

	// Variable storing user's input
	char* seat = new char[2];

	Display(rows, run, Num_of_rows);

	cout << "Welcome! The seats marked with X are not avaiable." << endl << endl;

	cout << "Please enter your desired seat number below. If not, enter 1K to exit" << endl;

	// Taking variable
	do {

		cin.getline(seat, 3);

		if (rows[seat[0] - 49][seat[1] - 64] == 'X') {

			cout << "The entered seat number is not available.\nPlease enter seat number again.\n";

		}

		if (seat[1] == 'K') {

			run = false;
		}

	} while (rows[seat[0] - 49][seat[1] - 64] == 'X' && seat[1] != 'K');

	// Terminating condition
	if (seat[1] == 'K') {

		run = false;
	}
	else {

		rows[seat[0] - 49][seat[1] - 64] = 'X';
	}

	return rows;
}

char** bookSeats(int Num_of_rows) {

	bool run = true;

	// Creating a 2D pointer
	char** rows = new char* [Num_of_rows];
	for (int i = 0; i < Num_of_rows; i++) {

		rows[i] = new char[5];
	}

	// Assigning numbers to rows
	for (int i = 0; i < Num_of_rows; i++) {

		rows[i][0] = char(i + 49);
		rows[i][5] = '\0';
	}	

	// Filling each row with alphabetical seat numbers
	for (int i = 0; i < Num_of_rows; i++) {

		for (int j = 0; j < 5; j++) {

			rows[i][j + 1] = char(j + 65);
		}
	}

	while (run == true) {

		// Function to book seats
		InputSeats(rows, run, Num_of_rows);
	}
		// To terminate program
		run = checkFull(rows, run, Num_of_rows);

	return rows;
}