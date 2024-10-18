/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 4			*/

#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class CMap {

	string value;
	string map[10][10];
	string key;
	int num1, num2, int_key;

public:

	CMap();
	string  toString();
	void display();

	CMap& operator[](string key1);
	CMap& operator += (string name);
	CMap& operator -= (string name);
	CMap& operator = (string name);
	CMap& operator = (const CMap obj);
	CMap& operator + (CMap obj);

	~CMap();
};