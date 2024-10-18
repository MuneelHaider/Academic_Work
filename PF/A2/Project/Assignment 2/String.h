#pragma once

class String {

	char* data = { };
	int length = 0;

public:

	String() {

		length = 0;
		*data = '\0';
	}
	String(int size) {

		length = size;
		data = new char[size + 1];
		data[0] = '\0';
	}
	String(char* str) {

		int size = 0;
		int i = 0;

		for (i = 0; *(str + i) != '\0'; i++) {

			size++;
		}

		length = size;

		data = new char[size];

		for (i = 0; i < size; i++) {

			*(data + i) = *(str + i);
		}

		*(data + i) = '\0';
	}
	String(const String& str) {

		data = str.data;

		length = str.length;
	}
	~String() {

	}

	int strLength();
	void clear();
	bool empty();
	int charAt(char c);
	char* getdata();
	bool equals(char* str);
	bool equalsIgnoreCase(char* str);
	char* substring(char* substr, int startindex);
	char* substring(char* substr, int startindex, int endindex);
	void print();
};