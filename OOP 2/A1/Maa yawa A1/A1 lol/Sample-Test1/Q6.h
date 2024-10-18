#pragma once
#include <iostream>
using namespace std;

/*	Muneel Haider
	21i-0640
	Assignment 1	*/

int find(int array[], int length, int target) {

	if (array[length] == target) {

		return length;
	}

	if (length <= 0) {

		return -1;
	}

	return find(array, --length, target);
}

void replace(char* s1, char ch1, char ch2) {

	if (*s1 == '\0') {

		return;
	}

	if (*s1 == ch1) {

		*s1 = ch2;
	}

	replace(++s1, ch1, ch2);
}

bool isPalindrome(char str[], int size) {

	size -= 1;

	if (str[size] - *str == 1 || *str == str[size]) {

		return 1;
	}

	if (*str == str[size] || *(str + 1) == str[size]) {

		return isPalindrome(++str, size);
	}

	else {

		return false;
	}
}

void printer(int number, char ch) {

	if (0 == number) {

		return;
	}

	cout << ch;
	printer(number - 1, ch);
}

void PrintPattern1(int n, int k, char ch1, char ch2) {
		
	if ((n - 1) < k) {
			
		cout << n;
		printer(n, ch1);
		n += 1;
	}
	else {

		k -= 1;
		if (k == 0) {

			cout << endl << "Question 6 Part C" << endl;
			return;
		}

		cout << k;
		printer(k, ch2);
	}

	PrintPattern1(n, k, ch1, ch2);
}

void printing(int value, char ch, bool flag) {

	if (flag == true) {

		while (value > 0) {

			cout << " ";
			value--;
		}
	}
	else {

		while (value > 0) {

			cout << ch;
			value--;
		}
		cout << endl;
	}
}

void PrintTriangle(int value, int value2, char ch, int number) {

	number = value - value2;
	if (number < 0) {

		number *= -1;
	}

	switch (value) {

	case 0:
	case 1:
		printing(value2, ch, false);
		break;

	default:
		printing(value - 1, ch, true);
		cout << ch;

		switch (number) {

		case 0:
			cout << endl;
			break;

		default:
			printing(number - 1, ch, true);
			cout << ch << endl;
			break;
		}

		PrintTriangle(value - 1, value2, ch, number);
		break;
	}
}

void PrintPattern(int value, char ch) {
	
	int number = 0;

	// So that we could use the original value later
	PrintTriangle(value, value, ch, number);
}