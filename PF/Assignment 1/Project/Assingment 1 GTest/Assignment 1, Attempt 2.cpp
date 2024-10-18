#include <iostream>
using namespace std;

char* convertToTapCode(char* word) {

	char* result = new char[200];

	for (int i = 0; word[i] != '\0'; i++) {

		result += '  ';

		if (word[i] == 'a' || word[i] == 'A') {

			result += '. .';
		}
		if (word[i] == 'b' || word[i] == 'B') {

			result += '. ..';
		}
		if (word[i] == 'c' || word[i] == 'C') {

			result += '. ';
			result += '...';
		}
		if (word[i] == 'd' || word[i] == 'D') {

			result += '. ';
			result += '....';
		}
		if (word[i] == 'e' || word[i] == 'E') {

			result += '. ';
			result += '.....';
		}
		if (word[i] == 'f' || word[i] == 'F') {

			cout << ".. .";
		}
		if (word[i] == 'g' || word[i] == 'G') {

			cout << ".. ..";
		}
		if (word[i] == 'h' || word[i] == 'H') {

			cout << ".. ...";
		}
		if (word[i] == 'i' || word[i] == 'I') {

			cout << ".. ....";
		}
		if (word[i] == 'j' || word[i] == 'J') {

			cout << ".. .....";
		}
		if (word[i] == 'k' || word[i] == 'K') {

			cout << ". ...";
		}
		if (word[i] == 'l' || word[i] == 'L') {

			cout << "... .";
		}
		if (word[i] == 'm' || word[i] == 'M') {

			cout << "... ..";
		}
		if (word[i] == 'n' || word[i] == 'N') {

			cout << "... ...";
		}
		if (word[i] == 'o' || word[i] == 'O') {

			cout << "... ....";
		}
		if (word[i] == 'p' || word[i] == 'P') {

			cout << "... .....";
		}
		if (word[i] == 'q' || word[i] == 'Q') {

			cout << ".... .";
		}
		if (word[i] == 'r' || word[i] == 'R') {

			cout << ".... ..";
		}
		if (word[i] == 's' || word[i] == 'S') {

			cout << ".... ...";
		}
		if (word[i] == 't' || word[i] == 'T') {

			cout << ".... ....";
		}
		if (word[i] == 'u' || word[i] == 'U') {

			cout << ".... .....";
		}
		if (word[i] == 'v' || word[i] == 'V') {

			cout << "..... .";
		}
		if (word[i] == 'w' || word[i] == 'W') {

			cout << "..... ..";
		}
		if (word[i] == 'x' || word[i] == 'V') {

			cout << "..... ...";
		}
		if (word[i] == 'y' || word[i] == 'Y') {

			cout << "..... ....";
		}
		if (word[i] == 'z' || word[i] == 'Z') {

			cout << "..... .....";
		}
	}
}

int main() {

	char word[50];
	cin >> word;
	char* ptr = &word[0];


	int counter = 0;
	for (int i = 0; word[i] != '\0'; i++) {

		counter++;
	}

	cout << endl << "The Tap Code:" << endl;
	char* code = convertToTapCode(ptr);

	for (int i = 0; *(code + i) != '\0'; i++) {

		cout << *(code + i);
	}
/*
	cout << endl << "The Original Word:" << endl;
	char* letters = convertToString(code);

	for (int i = 0; *(letters + i) != '\0'; i++) {

		cout << *(letters + i);
	}
*/
	return 0;
}