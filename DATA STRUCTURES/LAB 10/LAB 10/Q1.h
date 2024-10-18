#pragma once
#include <iostream>
#include <stack>
using namespace std;

/*	Muneel Haider 21i-0640 LAB 10	*/	

bool isBalanced(string s) {

	bool flag = false;

	stack<char> ss;

	for (int i = 0; s[i] != '\0'; i++) {

		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {

			ss.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {

			if (ss.empty()) {

				return false;
			}

			char top = ss.top();

			ss.pop();

			if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{')) {

				return false;
			}
		}

	}

	return ss.empty();
}

bool getPrecedence(char op1) {

	switch (op1) {

	case '^':
		return 3;

	case '*':
	case '/':
		return 2;
	
	case '+':
	case '-':
		return 1;
	
	default:
		return 0;
	}
}

string infixToPrefix(const string& data) {

	if (data.empty()) {

		return "";
	}

	string prefix = "";
	stack<char> ss;

	for (int i = data.size() - 1; i >= 0; i--) {

		char c = data[i];

		if (isalpha(c)) {

			prefix = c + prefix;
		}

		else if (c == ')') {

			ss.push(c);
		}

		else if (c == '(') {

			while (!ss.empty() && ss.top() != ')') {

				prefix = ss.top() + prefix;
				ss.pop();
			}

			if (ss.empty()) {

				throw invalid_argument("Invalid expression");
			}

			ss.pop();
		}
		else {

			while (!ss.empty() && getPrecedence(c) < getPrecedence(ss.top())) {

				prefix = ss.top() + prefix;
				ss.pop();
			}

			ss.push(c);
		}
	}
	while (!ss.empty()) {

		if (ss.top() == '(' || ss.top() == ')') {

			throw invalid_argument("Invalid expression");
		}

		prefix = ss.top() + prefix;
		ss.pop();
	}

	return prefix;
}