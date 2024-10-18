#pragma once
#include <iostream>
using namespace std;

class Node {

public:

	string letter;
	Node* next;
	Node* prev;

	Node(string d = "") {

		letter = d;
		next = NULL;
		prev = NULL;
	}
}*Top;

class DoubleLinkedList {

public:

	bool is_empty() {

		if (Top == NULL) {

			return true;
		}

		return false;
	}

	string Peaktop() {

		return Top->letter;
	}

	string top() {

		return Top->letter;
	}

	void push(string d) {

		Node* temp = new Node(d);

		temp->next = Top;

		Top = temp;
	}

	string pop() {

		string r;

		if (is_empty()) {

			cout << endl << "Empty Stack." << endl << endl;
		}
		else {

			Node* temp = Top;
			r = Top->letter;
			Top = Top->next;

			delete temp;
		}

		return r;
	}
};

int isOperator(char ch) {

	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {

		return 1;
	}

	return -1;
}

int isOperand(char ch) {

	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {

		return 1;
	}

	return 0;
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
//
//int precendence(string d) {
//
//	if (d == "+" || d == "-") {
//
//		return 6;
//	}
//	else if (d == "*" || d == "/" || d == "%") {
//
//		return 5;
//	}
//	else if (d == "^") {
//
//		return 12;
//	}
//
//	return -1;
//}
//
//bool preCheck(int a1, int a2) {
//
//	if (a1 > a2) {
//
//		return true;
//	}
//
//	return false;
//}
//
//int infix_to_postfix_A(string d, char* output, DoubleLinkedList ss) {
//
//	/*string result;
//
//	int a = 0, b = 0;
//
//	char letter;
//
//	for (int i = 0; i < d.length(); i++) {
//
//		if (isOperator(d[i]) != -1) {
//
//			a = ss->pop();
//
//			b = ss->pop();
//
//			ss->push(operations(a, b, d[i]));
//		}
//		else if (isOperand(d[i]) > 0) {
//
//			ss->push(scanNum(d[i]));
//		}
//	}
//
//	int r = ss->Peaktop();
//
//	result = to_string(r);
//
//	int r = result.length();
//
//	for (int i = 0; i < r; i++) {
//
//		ss->push(result[i]);
//	}
//
//	return 0;*/
//
//	string result;
//
//	for (int i = 0; d[i] != '\0'; i++) {
//
//		char letter = d[i];
//
//		if (isOperand(letter)) {
//
//			result += letter;
//		}
//		else {
//
//			while(!ss.is_empty() && preCheck(precendence(ss.Ptop()), precendence(to_string(letter)))) {
//			
//				string n = ss.pop();
//				result += n;
//			}
//
//			if (ss.is_empty() || letter != ')') {
//
//				ss.push(letter);
//			}
//			else {
//
//				string n = ss.pop();
//			}
//		}
//	}
//
//	while (!ss.is_empty()) {
//
//		string x = ss.pop();
//		result += x;
//	}
//
//	int o = result.length();
//	for (int i = 0; i < o; i++) {
//
//		ss.push(result[i]);
//	}
//
//	return 0;
//}

int precedence(char op) {
	if (op == '/')
		return 3;
	else if (op == '*')
		return 2;
	else if (op == '%')
		return 2;
	else if (op == '^')
		return 1;
	else if (op == '+')
		return 0;
	else if (op == '-')
		return 0;
	else if (op == 'A' || op == 'a')
		return 4; // ABC operator
	else
		return -1; // Invalid operator
}

int infix_to_postfix_A(string infix, char output_stack[], DoubleLinkedList& operator_stack) {
	int pos = 0;
	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];
		if (c == ' ' || c == '\t')
			continue;
		else if (c == '(')
			operator_stack.push("(");
		else if (c == ')') {
			while (operator_stack.Peaktop() != "(") {
				string op = operator_stack.pop();
				output_stack[pos++] = op[0];
			}
			operator_stack.pop(); // Pop the left parenthesis
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == 'A' || c == 'a') {
			string op(1, c);
			int op_prec = precedence(c);
			while (!operator_stack.is_empty() && operator_stack.Peaktop() != "(" && op_prec <= precedence(operator_stack.Peaktop()[0])) {
				string top_op = operator_stack.pop();
				output_stack[pos++] = top_op[0];
			}
			operator_stack.push(op);
		}
		else { // Operand
			output_stack[pos++] = c;
		}
	}
	while (!operator_stack.is_empty()) {
		string op = operator_stack.pop();
		output_stack[pos++] = op[0];
	}
	output_stack[pos] = '\0';
	return pos;
}
