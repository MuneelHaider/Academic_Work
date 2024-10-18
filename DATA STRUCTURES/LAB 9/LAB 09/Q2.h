#pragma once
#include<iostream>
#include "Q1.h"
using namespace std;

/*		Muneel Haider
		21i-0640
		LAB 9				
		Question 2			*/

bool validate(string s) {

	bool flag = false;
	
	stack<char> ss;
	
	for (int i = 0; s[i] != '\0'; i++) {

		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {

			ss.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {

			if (ss.IsEmpty()) {

				return false;
			}

			char top = ss.top->val;

			ss.pop();

			if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{')) {

				return false;
			}
		}

	}

	return ss.IsEmpty();
}