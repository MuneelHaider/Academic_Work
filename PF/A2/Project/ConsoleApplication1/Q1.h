#pragma once
#include <iostream>

class TestScores {

	int index = 0;
	int* length = new int[index];

public:

	TestScores(int array[]) {

		for (int i = 0; i < 5; i++) {

			*(length + i) = array[i];
			index = i;
		}		
	};

	int getScoreAverage()
	{
		for (int i = 0; i < 5; i++) {

			if (*(length + i) < 0 || *(length + i) > 100) {

				return 0;
			}
		}
		
		int A = 0, sum = 0;
		int counter = 0;
		while (counter != 5) {

			sum += *(length + counter);
			counter++;
		}

		A = sum / counter;

		return A;
	}
};