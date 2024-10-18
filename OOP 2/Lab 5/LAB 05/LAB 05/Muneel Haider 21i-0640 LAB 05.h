#pragma once
#include<string>
#include<iostream>
using namespace std;

/*		Muneel Haider		*
*		21i-0640			*
*		LAB 05				*/

int LCM(int a, int b, int c) {

	if (b == 0) {

		return a;
    }

	return LCM(b, a % b, 1);
}

int LCM(int num1, int num2) {

	return (num1 / LCM(num1, num2, 1) * num2);
}

int Power(int a,int b) {

	if (b != 0) {

		return (a * Power(a, b - 1));
	}
	else {

		return 1;
	}
}

char** reverse_sentence(char** sentence, int words, int size, int counter, int no_of_words) {

	char* temp = new char[size];
	*temp = '\0';

	if (no_of_words % 2 == 0) {

		if (counter == words + 1) {

			return sentence;
		}

		temp = sentence[words];
		sentence[words] = sentence[counter];
		sentence[counter] = temp;
	}
	else {

		if (counter == words) {

			return sentence;
		}

		temp = sentence[words];
		sentence[words] = sentence[counter];
		sentence[counter] = temp;
	}

	reverse_sentence(sentence, words - 1, size, counter + 1, no_of_words);
}

char** reverse_sentence(char** sentence, int words, int size) {

	int counter = 0;
	int no_of_words = words;

	sentence = reverse_sentence(sentence, words - 1, size, counter, no_of_words);

	return sentence;
}

int* sequence(int num,int* result,int size, int counter) {

	if (*result % 2 == 0) {

		*(result + 1)  = *result / 2;
	}

	else if (*result == 1) {

		return result;
	}

	else if(*result % 2 != 0) {

		*(result + 1) = (*result * 3) + 1;
	}

	sequence(num, ++result, size, 1);
}

int* sequence(int num, int* result, int size) {

	*result = num;

	sequence(num, result, size, 1);

	return result;
}