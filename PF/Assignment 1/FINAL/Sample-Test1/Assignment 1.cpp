#include<iostream>
using namespace std;

char* convertToTapCode(char* ptr) {

	int dots_one = 0, dots_two = 0, position = 0, ascii = 0, aascii = 0, bascii = 0;
	char* code = new char[500];

	for (int j = 0; *(ptr + j) != '\0'; j++) {

		ascii = *(ptr + j);

			if (ascii > 96) {

				if (ascii > 107) {

					ascii = ascii - 1;
				}
				else if (ascii == 107) {

					ascii = 99;
				}

				aascii = ascii - 96;

				if (aascii % 5 == 0) {

					dots_one = aascii / 5;
					dots_two = 5;
				}
				else {

					dots_one = 1 + (aascii / 5);
					dots_two = aascii % 5;
				}

				for (int i = 0; i < dots_one; i++) {

					*(code + position++) = '.';
				}

				{
					*(code + position++) = '.';
				}

				for (int i = 0; i < dots_two; i++) {

					*(code + position++) = '.';
				}

				if (*(ptr + j + 1) != '\0') {

					*(code + position++) = ' ';
					*(code + position++) = ' ';
				}
			}

			else{
			
				if (ascii > 75) {

					ascii = ascii - 1;
				}
				else if (ascii == 75) {

					ascii = 67;
				}

				bascii = ascii - 64;

				if (bascii % 5 == 0) {

					dots_one = bascii / 5;
					dots_two = 5;
				}
				else {

					dots_one = 1 + (bascii / 5);
					dots_two = bascii % 5;
				}

				for (int i = 0; i < dots_one; i++) {

					*(code + position++) = '.';
				}

				{
					*(code + position++) = ' ';
				}

				for (int i = 0; i < dots_two; i++) {

					*(code + position++) = '.';
				}

				if (*(ptr + j + 1) != '\0') {

					*(code + position++) = ' ';
					*(code + position++) = ' ';
				}
			}
	}
	*(code + position) = '\0';

	return code;
}

char* convertToString(char* code) {

	int dots_one = 0, dots_two = 0, ascii = 0, position = 0, counter = 0;
	char* word = new char[300];

	while (*(code + counter - 2) != '\0') {

		for (; *(code + counter) == '.'; counter++) {

			dots_one++;
		}
		counter++;

		for (; *(code + counter) == '.'; counter++) {

			dots_two++;
		}

		counter += 2;

		if (dots_two == 5) {

			ascii = (dots_one * dots_two) + 96;
		}
		else {

			ascii = (5 * (dots_one - 1)) + dots_two + 96;
		}
		
		if (ascii > 107) {

			ascii++;
		}

		*(word + position++) = char(ascii);
		
		dots_one = 0;
		dots_two = 0;
	}

	*(word + position) = '\0';

	return word;
}

int main() {

	char word[50];
	cin >> word;
	char* ptr = &word[0];
	

	int counter = 0;
	for (int i = 0;word[i]!='\0'; i++) {

		counter++;
	}

	cout << endl << "The Tap Code:" << endl;
	char* code = convertToTapCode(ptr);

	for (int i = 0; *(code + i) != '\0'; i++) {

		cout << *(code + i);
	}

	cout << endl << "The Original Word:" << endl;
	char* letters = convertToString(code);

	for (int i = 0; *(letters + i) != '\0'; i++) {

		cout << *(letters + i);
	}

	return 0;
}