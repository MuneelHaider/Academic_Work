#include <iostream>
#include "pch.h"
#include "String.h"
using namespace std;

String::String() {

	length = 0;
	data = NULL;
}
String::String(int size) {

	length = size;
	data = new char[size + 1];
	data[0] = '\0';
}
String::String(char* str) {

	int size = 0;
	int i = 0;

	for (i = 0; *(str + i) != '\0'; i++) {

		size++;
	}

	length = size;

	data = new char[size + 1];

	for (i = 0; i < size; i++) {

		*(data + i) = *(str + i);
	}

	*(data + i) = '\0';
}
String::String(const String& str) {


	length = str.length;

	data = new char[length + 1];

	for (int i = 0; i < length; i++) {

		data[i] = str.data[i];

	}
}
String::~String() {

	delete[] data;
}

void String::print() {

	if (length == 0) {

		cout << "null" << endl;
	}
	else {

		cout << data;
	}
}

char* String::substring(char* substr, int startindex) {
	
	int size = 0, counter = 0;
	int index = startindex;
	int secondindex;

	char* answer = new char[length - index];

	for (size = 0; *(substr + size) != NULL; size++) {

	}

	while (index < length + index) {

		while (*(data + index + counter) == *(substr + counter)) {

			counter++;
		}

		if (size <= counter) {

			secondindex = index;

			for (int i = 0; i < length + index; i++) {

				*(answer + i) = *(data + secondindex);
				
				if (length - secondindex + 1 == 1) {

					*(answer + i + 1) = NULL;
				}

				secondindex++;
			}
			return answer;
		}

		index++;
	}

	return NULL;
}

char* String::substring(char* substr, int startindex, int endindex) {


	int size = 0, counter = 0;
	int index = startindex;
	int secondindex;

	char* answer = new char[endindex - index];

	for (size = 0; *(substr + size) != NULL; size++) {

	}

	while (index < endindex + index) {

		while (*(data + index + counter) == *(substr + counter)) {

			counter++;
		}

		if (size <= counter) {

			secondindex = index;

			for (int i = 0; i < endindex + index; i++) {

				*(answer + i) = *(data + secondindex);

				if (endindex - secondindex + 1 == 1) {

					*(answer + i + 1) = NULL;
				}

				secondindex++;
			}
			return answer;
		}

		index++;
	}

	return NULL;
} 

bool String::equalsIgnoreCase(char* str) {

	for (int i = 0; *(data + i) != '\0'; i++) {

		if (*(data + i) > 64 && *(data + i) < 91) {

			*(data + i) = *(data + i) + 32;
		}
		if (*(str + i) > 64 && *(str + i) < 91) {

			*(str + i) = *(str + i) + 32;
		}
	}

	for (int i = 0; *(data + i) != '\0'; i++) {

		if (*(data + i) != *(str + i)) {

			return false;
		}
	}

	return true;
}

bool String::equals(char* str) {

	for (int i = 0; *(data + i) != '\0'; i++) {

		if (*(data + i) != *(str + i)) {

			return false;
		}
	}

	return true;
}

char* String::getdata() {

	return data;
}

int String::charAt(char c) {

	int counter = 0;
	
	for (counter = 0; *(data + counter) != '\0'; counter++) {

		if (*(data + counter) == c) {

			return counter;
		}
	}

	return 0;
}

int String::strLength() {

	return length;
}

void String::clear() {

	length = 0;
	*(data) = '\0';
}

bool String::empty() {

	if (*data == '\0') {

		return true;
	}
	else {

		return false;
	}
}