#include <iostream>
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