#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

void countLetters(char* ptr, int*& array, int& size) {

	for (int i = 0; *(ptr + i) != '\0'; i++) {

		size++;
	}

	int counter = 0;
	int ascii[20] = {0};
	int value[20] = { 0 };
	int usedletters[20] = {0};
	bool usedornot = false;
	int usedcounter = 0;

	for (int j = 0; j < size; j++) {

		usedornot = false;

		for (int k = 0; k < usedcounter; k++) {

			if (*(ptr + j) == usedletters[k]) {

				usedornot = true;

			}

		}

		if (!usedornot) {

			for (int i = 0; i < size; i++) {

				if (*(ptr + i) == *(ptr + j)) {

					value[usedcounter]++;

				}

			}

			

			usedletters[usedcounter] = *(ptr + j);
			usedcounter++;

		}

	}

	for (int i = 0; i < usedcounter; i++) {

		cout << char(usedletters[i]) << value[i] << " ";
	}

	for (int i = 0; i < usedcounter; i++) {

		array[i] = value[i];
	}

	size = usedcounter;
}





	
void removePunctuation(char* ptr) {

	char result[100] = { NULL };
	char* ptr2 = &result[0];

	int counter = 0;
	for (int i = 0; *(ptr + i) != '\0'; i++) {

		if (*(ptr + i) >= 65 && *(ptr + i) <= 90) {

			*(ptr2 + (counter++)) += *(ptr + i);
		}
		else if (*(ptr + i) >= 97 && *(ptr + i) <= 122) {

			*(ptr2 + (counter++)) += *(ptr + i);
		}
		else if (*(ptr + i) == 32) {

			*(ptr2 + (counter++)) += *(ptr + i);
		}
	}
	for (int i = 0; *(ptr + i) != '\0'; i++) {

		*(ptr + i) = ' ';
	}

	/**(ptr + 0) = NULL;*/
	int j = 0;

	for (int i = 0; i < counter; i++) {

		*(ptr + (j++)) = *(ptr2 + i);
	}
}