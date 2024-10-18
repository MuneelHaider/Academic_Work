#include <iostream>
using namespace std;

int main() {

	char** sentence = new char* [4];
	for (int i = 0; i < 4; i++) {

		sentence[i] = new char[6];
	}

	*(*(sentence + 0) + 0) = 'h';
	*(*(sentence + 0) + 1) = 'e';
	*(*(sentence + 0) + 2) = 'l';
	*(*(sentence + 0) + 3) = 'l';
	*(*(sentence + 0) + 4) = 'o';
	*(*(sentence + 0) + 5) = '\0';
 
	*(*(sentence + 1) + 0) = 'h';
	*(*(sentence + 1) + 1) = 'o';
	*(*(sentence + 1) + 2) = 'w';
	*(*(sentence + 1) + 3) = '\0';

	*(*(sentence + 2) + 0) = 'a';
	*(*(sentence + 2) + 1) = 'r';
	*(*(sentence + 2) + 2) = 'e';
	*(*(sentence + 2) + 3) = '\0';
 
	*(*(sentence + 3) + 0) = 'y';
	*(*(sentence + 3) + 1) = 'o';
	*(*(sentence + 3) + 2) = 'u';
	*(*(sentence + 3) + 3) = '?';
	*(*(sentence + 3) + 4) = '\0';
 
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 6; j++) {

			cout << *(*(sentence + i) + j) << " ";
		}

		if (i == 1) {

			++i;
		}
	}


	return 0;
}