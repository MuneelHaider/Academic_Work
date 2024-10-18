/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 4			*/

#include "pch.h"
#include "CMap.h"
#include <iostream>
#include <string>

using namespace std;

CMap::CMap() {

	value = " ";
	num1 = 0; 
	num2 = 0; 
	int_key = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
	
			map[i][j] = " ";
		}
	}
}

string CMap::toString() {

	value = "[";

	for (int i = 0; i < num1 - int_key; i++) {

		if (i > 0) {

			value += ",";
		}

		value += " ";
		value += map[i][0];
		value += " : {";

		for (int j = 1; j < num2; j++) {

			if (map[i][j] != " ") {
				
				if (j > 1) {
				
					value += ",";
				}
				
				value += " ";
				value += map[i][j];
			}
		}

		value += " }";;
	}

	value += " ]";

	return value;
}

void CMap::display() {

	cout << value << endl << endl;
}

CMap& CMap::operator [](string keyVal) {

	key = keyVal;

	return *this;
}

CMap& CMap::operator +=(string name) {

	for (int i = 0; i < 10; i++) {
		
		if (map[i][0] == key) {

			for (int j = 0; j < 10; j++) {

				if (map[i][j] == " ") {
					
					map[i][j] = name;
		
					num2++;
					
					break;
				}
			}

			break;
		}
	}

	return *this;
}

CMap& CMap::operator -=(string name) {

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (map[i][j] == name) {

				map[i][j] = map[i][j + 1];
				map[i][j + 1] = "";
			
				num2--;

				break;
			}
		}
	}

	return *this;
}

CMap& CMap::operator =(string name) {


	value = name;


	for (int i = 0; i < 10; i++) {

		if (map[i][0] == key) {

			int_key++;
		}
	}

	for (int i = 0; i < 10; i++) {

		if ((map[i][0] != key && map[i][0] == " ") || map[i][0] == key) {

			for (int j = 0; j < 10; j++) {
			
				if (map[i][j] != " ") {
				
					map[i][j] = value;
					
					break;
				}
			}

			map[i][0] = key;
			map[i][1] = value;

			num1++;
			num2++;

			break;
		}
	}

	return *this;
}

CMap& CMap::operator =(const CMap obj) {

	num1 = obj.num1;
	num2 = obj.num2;
	int_key = obj.int_key;

	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 10; j++) {

			map[i][j] = obj.map[i][j];
		}
	}

	return  *this;
}

CMap& CMap::operator +(CMap obj) {

	value += obj.value;

	return *this;
}

CMap::~CMap() {

}