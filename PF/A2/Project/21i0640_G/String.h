#pragma once

class String {

	char* data = { };
	int length = 0;

public:

	String();
	String(int size);
	String(char* str);
	String(const String& str);
	~String();

	int strLength();
	void clear();
	bool empty();
	char* getdata();
	int charAt(char);
	bool equals(char*);
	bool equalsIgnoreCase(char*);
	char* substring(char*, int);
	char* substring(char*, int, int);
	void print();
};