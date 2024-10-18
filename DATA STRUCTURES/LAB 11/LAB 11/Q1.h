#pragma once
#include <iostream>
#include <stack>
using namespace std;

int isOperator(char ch) {

	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {

		return 1;
	}	
	
	return -1;
}

int isOperand(char ch) {

	if (ch >= '0' && ch <= '9') {

		return 1;
	}

	return -1;
}


float operations(int a, int b, char ch) {

	if (ch == '+') {

		return b + a;
	}
	else if (ch == '-') {

		return b - a;
	}
	else if (ch == '*') {

		return b * a;
	}
	else if (ch == '/') {

		return b / a;
	}
	else if (ch == '^') {
	
		return pow(b, a);
	}
	else {

		return -1;
	}
}

float scanNum(char ch) {
	
	int value;
	
	value = ch;
	
	return float(value - '0');//return float from character
}

string evaluatePostfixExpression(string d) {

	string result;

	int a = 0, b = 0;

	stack<int> ss;

	char letter;

	for (int i = 0; i < d.length(); i++) {

		if (isOperator(d[i]) != -1) {

			a = ss.top();
			ss.pop();

			b = ss.top();
			ss.pop();
			
			ss.push(operations(a, b, d[i]));
		}
		else if (isOperand(d[i]) > 0) {

			ss.push(scanNum(d[i]));
		}
		if (d[i] == '/' && d[i - 2] == '0') {

			return "Error: division by zero";
		}
	}

	int r = ss.top();

	result = to_string(r);

	return result;
}