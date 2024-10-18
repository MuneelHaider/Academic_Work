#include <iostream>
using namespace std;

bool isprimeNumber(int number, int i = 2) {

	bool flag = true;

	if(number < 2) {
		
		return false;
	}

	if(number % i == 0) {

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
	
	if () {

		flag = false;
	}

	else if(start == 0) {
	
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