#pragma once
#include <iostream>
using namespace std;

/*	Muneel Haider
	21i-0640
	Assignment 1	*/

int returnTotalVotes(int candidates, int* votes) {

	int total = 0;

	for (int i = 0; i < candidates; i++) {

		total += votes[i];
	}

	return total;
}

float* allocatePercentages(int candidates, int* votes) {

	float* ptr = new float[candidates];
	int totalVotes = returnTotalVotes(candidates, votes);

	for (int i = 0; i < candidates; i++) {

		ptr[i] = (votes[i] / float(totalVotes)) * 100;
	}

	return ptr;
}

int* allocateVotes(int candidates) {

	int* ptr = new int[candidates];

	for (int i = 0; i < candidates; i++) {

		ptr[i] = -1;
	}

	return ptr;
}

char** allocateNames(int candidates) {

	char** ptr = new char* [candidates];
	for (int i = 0; i < candidates; i++) {

		ptr[i] = new char;
		ptr[i] = '\0';
	}

	return ptr;
}

void setVotes(int candidates, char** names, char* name, int*& votes, int VotesVal) {

	bool loop = true;

	for (int i = 0; i < candidates && loop == true; i++) {

		if (votes[i] == -1) {

			votes[i] = VotesVal;
			break;
		}
	}
}

void setNames(int candidates, char**& names, char* name) {

	bool loop = true;

	for (int i = 0; i < candidates && loop == true; i++) {

		if (names[i] == '\0') {

			names[i] = name;
			break;
		}
	}
}

void WhoWin(int candidates, char** names, int* votes) {

	float* ptr = new float[candidates];
	int totalVotes = returnTotalVotes(candidates, votes);

	for (int i = 0; i < candidates; i++) {

		ptr[i] = (votes[i] / float(totalVotes)) * 100;
	}

	int max = 0;
	int counter = 0;
	for (int i = 0; i < candidates; i++) {

		if (ptr[i] > max) {

			max = ptr[i];
			counter = i;
		}
	}

	cout << "The winner of the elections is " << names[counter]
		 << " with a total votes of " << votes[counter] 
		 << " winning with a majority of " << ptr[counter] << "." << endl;

	cout << endl << "The total number of votes for all candidates was " 
		 << totalVotes << "." << endl << endl;
}