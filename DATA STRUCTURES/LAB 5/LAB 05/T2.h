#pragma once
#include <iostream>
#include <string>
#include "string.h"
using namespace std;

bool PasswordValidation(string s) {

	int size = s.length();
	bool f4 = false;
	bool f1 = false;
	bool f2 = false;
	bool f3 = false;

	for (int i = 0; i < size; i++) {

		if (s[i] >= '1' && s[i] <= '9') {

			f1 = true;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {

			f2 = true;
		}
		if (s[i] >= 32 && s[i] <= '/') {

			f3 = true;
		}
		if (size > 5 && size < 11) {

			f4 = true;
		}
	}

	if (f1 == true && f2 == true && f3 == true && f4 == true) {

		return true;
	}

	return false;
}

bool EmailValidation(string s) {

	int size = s.length();
	int count = 0;
	bool f1 = false;
	bool f2 = true;
	bool f3 = true;
	bool f4 = true;
	bool f5 = false;
	bool f6 = false;

	for (int i = 0; i < size; i++) {

		if (s[0] >= 'a' && s[0] <= 'z') {

			f1 = true;
		}
		if (s[i] >= 44 && s[i] <= 46) {

			count++;

			if (count == 4) {

				f2 = false;
			}
		}
		if (s[i] >= 44 && s[i] <= 46 && s[i + 1] >= 44 && s[i + 1] <= 46) {

			f3 = false;
		}
		if (s[i] == '@') {

			f5 = true;

			if (s[i - 1] >= 44 && s[i - 1] <= 46) {

				f4 = false;
			}
		}

		if (s[i] == '.' && s[i + 1] == 'c' && s[i + 2] == 'o' && s[i + 3] == 'm') {

			f6 = true;
		}
		
	}

	if (f1 == true && f2 == true && f3 == true && f4 == true && f5 == true && f6 == true) {

		return true;
	}

	return false;
}