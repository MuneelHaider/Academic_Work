#pragma once
#include <iostream>
using namespace std;

/*	Muneel Haider
	21i-0640
	Assignment 1	*/

void calculateHistogram(int* marks, int*& result, int totalCount) {

	result = new int[71];

	for (int i = 0; i < 71; i++) {

		result[i] = 0;
	}

	for (int i = 0;i < totalCount; i++) {

		result[marks[i]]++;
	}

	int counter = 0;
	bool loop = true;
	int* ptr = new int[totalCount];
	*ptr = NULL;

	for (int i = 0; i < totalCount; i++) {

		loop = true;

		for (int j = 0; j < totalCount; j++) {

			if (marks[i] == ptr[j]) {

				loop = false;
				break;
			}
		}

		if(loop == true) {

			cout << "The frequency of " << marks[i] << " is:  " << result[marks[i]]
				<< ". " << endl;
			ptr[counter++] = marks[i];
		}
	}
}