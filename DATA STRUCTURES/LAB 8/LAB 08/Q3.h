#pragma once
#include <iostream>
#include <string>
using namespace std;

class Noder {

public:

	string data;
	Noder* next;

	Noder(string d = "") {

		data = d;
	}

};

class Stringer {

public:

	Noder* front;
	Noder* rear;

	Stringer() {

		front = NULL;
		rear = NULL;
	}


};

void mainOfQ3(string d) {

	char array[20];
	int i = 0;
	int size = d.length();
	int counter = 0;
	int words = 4;
	string temp;
	string t1;
	string t2;
	string t3;
	char result[50];
	int index = 0;
	

	for (int counter = 0; i < size;i++) {

		if (d[i] == ' ') {

			i++;
		}

		result[counter] = d[i];
		counter++;
	}

	result[counter] = '\0';

	cout << result;
	cout << "Hello";
}