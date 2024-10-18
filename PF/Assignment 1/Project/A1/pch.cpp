#include <iostream>
#include "pch.h"
using namespace std;



char* convertToString(char* ptr) {

	char* word = new char[20];

	int dots_one = 0, dots_two = 0, ascii = 0, counter = 0;

	for (int i = 0; *(ptr + i - 2) != NULL; counter++) {

		for (; *(ptr + i) == '.'; i++) {

			dots_one++;
		}

		i++;

		for (; *(ptr + i) == '.'; i++) {

			dots_two++;
		}

		i += 2;

			if (dots_one == 5) {

                ascii = 96 + (dots_one * dots_two);
                cout << ascii << "  2  " << endl;
			}

			else if (dots_two == 5) {

				ascii = 96 + (dots_one * dots_two);
				cout << ascii << "  2  " << endl;
			}

			word[counter] = char(ascii);

		dots_one = 0;
		dots_two = 0;
	}

	*(word + counter) = NULL;

	return word;
}









char* convertToTapCode(char* ptr) {

	int row = 0, column = 0, counter = 0;

	char array[5][5] = { {'a', 'b', 'c', 'd', 'e'},
						{'f', 'g', 'h', 'i', 'j'},
						{'l', 'm', 'n', 'o', 'p'},
						{'q', 'r', 's', 't', 'u'},
						{'v', 'w', 'x', 'y', 'z'} };

	char* code = new char[100];

	for (int i = 0; i < 100; i++) {

		*(code + i) = ' ';
	}

	for (int i = 0; *(ptr + i) != '\0'; i++) {

		if (*(ptr + i) == 'k') {

			column = 3;
			row = 1;
		}

		for (int j = 0; j <= 4; j++) {

			for (int m = 0; m <= 4; m++) {

				if (*(ptr + i) == array[j][m]) {

					column = m + 1;
					row = j + 1;
				}
			}
		}

		for (int j = 0; j < row; j++) {

			*(code + counter++) = '.';
		}

		*(code + counter++) = ' ';

		for (int j = 0; j < column; j++) {

			*(code + counter++) = '.';
		}

		for (int j = 0; j < 2; j++) {

			*(code + counter++) = ' ';
		}
	}

	*(code + (counter - 2)) = NULL;
	return code;
}

void countLetters(char* ptr, int*& array, int& size) {

	for (int i = 0; *(ptr + i) != '\0'; i++) {

		size++;
	}

	int counter = 0;
	int ascii[20] = { 0 };
	int value[20] = { 0 };
	int usedletters[20] = { 0 };
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

bool isprimeNumber(int number, int i = 2) {

	bool flag = true;

	if (number < 2) {

		return false;
	}

	if (number % i == 0) {

		return false;
	}

	if (i * i > number) {

		return true;
	}

	flag = isprimeNumber(number, ++i);

	return flag;
}

char findUppercase(char* ptr) {

	if (*ptr > 64 && *ptr < 91) {

		return *ptr;
	}

	if (*ptr == '\0') {

		return NULL;
	}

	return findUppercase(ptr + 1);
}

int sum(int** array, int row, int column, int& evenSum, int& oddSum) {

	static int x = column;
	if (array[row][column] % 2 == 0) {

		evenSum += array[row][column];
	}
	else {

		oddSum += array[row][column];
	}
	if (column > 0) {

		return sum(array, row, column - 1, evenSum, oddSum);
	}
	else if (row > 0) {

		--row;
		column = x;
		return sum(array, row, column, evenSum, oddSum);
	}
	else {

		return 0;
	}
}

void PrintPattern(int start, int end) {

	bool flag = true;

	if (start == 5) {

		flag = false;
	}

	else if (start == 0) {

		flag = true;
	}

	if (flag == true) {

		cout << "*" << endl;
		PrintPattern(start + 1, end);
	}
	if (flag == false) {

		cout << " " << endl;
		PrintPattern(start + 1, end);
	}
}