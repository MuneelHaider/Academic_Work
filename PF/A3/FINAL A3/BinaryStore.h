/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 5			*/

#pragma once
#include <iostream>
using namespace std;

class Byte {

public:

	char* character;
	char* b_byte;

	Byte();
	Byte(char*);
	char* getByte();

	bool operator ==(Byte);
	Byte operator +(Byte);
	Byte operator -(Byte);
	Byte operator ||(Byte);
	Byte operator &&(Byte);
};

class BinaryStore {

public:

	char* bt;
	char* address;
	char* bs_byte;

	BinaryStore();
	BinaryStore(int);
	
	void Add(char*, Byte);
	char* getByte();
	void setSize(int);

	BinaryStore operator +=(const char*);
	BinaryStore Get(char*);
};