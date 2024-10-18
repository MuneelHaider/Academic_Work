#pragma once
#include <iostream>
using namespace std;

class Integer {

	int number;
	string array;

public:

	Integer() {

		number = 0;
		array = '\0';
	}
	Integer(int n) {

		number = n;
		array = '\0';
	}
	Integer(string s) {

		number = 0;
		array = s;
	}
	Integer(int n, string s) {

		number = n;
		array = s;
	}

	void set(int n) {

		number = n;
	}
	int get() const {

		return number;
	}

	int bitCount() {

		int temp = number;
		int r = 0;
		int multi = 1;
		int sum = 0;
		int counter = 0;
		int index = 0;
		char result[32] = "";
		char final[32] = "";

		while (temp != 0) {

			r = temp % 2;

			result[index++] = char(r + 48);

			if (r == 1) {

				counter++;
			}

			sum += r * multi;
			temp /= 2;
			multi *= 10;
		}

		for (int i = 0; i < index; i++) {

			if (result[i] == '0') {

				final[i] = '1';
			}
			else {

				final[i] = '0';
			}
		}

		for (int i = index - 1; i >= 0; i--) {

			if (final[i] == '1') {

				result[i] = '0';
			}
			else {

				result[i] = '1';
				break;
			}
		}

		sum = 0;

		for (int i = 0; i < index; i++) {

			if (result[i] == '1') {

				sum++;
			}
		}

		return sum;
	}
	int compareTo(Integer obj) {

		// Returns 0 if calling object's number is less than argument's number
		// Returns 1 if calling object's number is greater than argument's number

		int comparison = 0;

		if (this->number >= obj.number) {

			comparison = 1;
		}
		else {

			comparison = 0;
		}

		return comparison;
	}
	double doubleValue() {

		double temp;

		temp = number;

		return temp;
	}
	float floatValue() {

		float temp;

		temp = number;

		return temp;
	}
	
	Integer plus(const Integer obj) {

		this->number += obj.number;

		return *this;
	}
	Integer minus(const Integer obj) {

		this->number -= obj.number;

		return *this;
	}
	Integer multiple(const Integer obj) {

		this->number *= obj.number;

		return *this;
	}
	Integer divide(const Integer obj) {

		this->number /= obj.number;

		return *this;
	}

	static int numberOfLeadingZeros(int i) {


		int temp = i;
		int r = 0;
		int multi = 25;
		int sum = 0;
		int counter = 0;
		int j = 0;
		string final = "";

		while (temp != 0) {

			r = temp % 2;

			counter++;

			final += char(r + 48);

			temp /= 2;
		}

		if (counter <= 8) {

			final += final[counter];

			for (int i = counter; i > 0; i--) {

				final[i] = final[i - 1];
			}

			for (int i = counter; i < 8; i++) {

				final[j++] = '0';
			}
		}

		j = 0;

		for (j = 0; j < counter; j++) {

			if (final[j] == '1') {

				final[j] = '0';
			}
			else {

				final[j] = '1';
			}
		}
		final[j] = '1';

		multi = 32 - counter;
		return multi;
	}
	static int numberOfTrailingZeros(int i) {
		int temp = i;
		int r = 0;
		int multi = 25;
		int sum = 0;
		int counter = 0;
		int j = 0;
		string final = "";

		while (temp != 0) {

			r = temp % 2;

			counter++;

			final += char(r + 48);

			temp /= 2;
		}

		if (counter <= 8) {

			final += final[counter];

			for (int i = counter; i > 0; i--) {

				final[i] = final[i - 1];
			}

			for (int i = counter; i < 8; i++) {

				final[j++] = '0';
			}
		}

		j = 0;

		for (j = 0; j < counter; j++) {

			if (final[j] == '1') {

				final[j] = '0';
			}
			else {

				final[j] = '1';
			}
		}

		multi = 0;
		final[j] = '1';

		for (int i = j; i < j; i++) {

			if (final[i] == '0') {

				multi++;
			}
		}

		return multi;
	}

	static string toBinaryString(int i) {

		int temp = i;
		int r = 0;
		int multi = 1;
		int sum = 0;
		int counter = 0;
		int j = 0;
		string final = "";

		while (temp != 0) {

			r = temp % 2;

			counter++;

			final += char(r + 48);

			temp /= 2;
		}

		if (counter <= 8) {

			final += final[counter];

			for (int i = counter; i > 0; i--) {

				final[i] = final[i - 1];
			}

			for (int i = counter; i < 8; i++) {

				final[j++] = '0';
			}
		}

		return final;
	}
	static string toHexString(int n) {

		char* final = new char[20];
		char* lmao = new char[20];
		int i = 0;
		int j = 0;
		int temp = 0;
		int counter = 0;

		while (n != 0) {

			temp = n % 16;

			if (temp < 10) {

				final[i++] = temp + 48;
			}
			else {

				final[i++] = temp + 55;
			}

			counter++;

			n = n / 16;
		}

		final[i--] = '\0';
		
		for (j = 0; j < counter; j++) {

			lmao[j] = final[i--];
		}

		lmao[j] = '\0';

		return lmao;
	}
	static string toOctString(int n) {

		char* final = new char[20];
		char* lmao = new char[20];
		int i = 0;
		int j = 0;
		int temp = 0;
		int counter = 0;

		while (n != 0) {

			temp = n % 8;

			final[i++] = temp + 48;
		
			counter++;

			n = n / 8;
		}

		final[i--] = '\0';

		for (j = 0; j < counter; j++) {

			lmao[j] = final[i--];
		}

		lmao[j] = '\0';

		return lmao;
	}
};