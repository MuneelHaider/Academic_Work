/*		Muneel Haider		*
 *		21i-0640			*
 *		Assignment 3		*
 *		Question 5			*/

#include "pch.h"
#include "BinaryStore.h"
#include <iostream>
using namespace std;

Byte::Byte() {

	b_byte = '\0';
	character = '\0';
}

Byte::Byte(char* ptr) {

	character = new char[8];

	int i = 0;

	while (i < 8) {

		character[i] = ptr[i];
		i++;
	}

	character[i] = '\0';
}

char* Byte::getByte() {

	b_byte = new char[8];

	int i = 0;

	while (i < 8) {

		b_byte[i] = character[i];
		i++;
	}

	b_byte[i] = '\0';

	return b_byte;
}

bool Byte::operator ==(Byte obj) {

	for (int i = 0; i < 8; i++) {

		if (character[i] != obj.character[i]) {

			return false;
		}
	}

	return true;
}

Byte Byte::operator +(Byte obj) {

	character[8] = '\0';

	for (int i = 7; i > -1; i--) {

		if (character[i] == 48 && obj.character[i] == 48) {

			character[i] = 48;
		}

		else if ((character[i] == 49 && obj.character[i] == 48) || (character[i] == 48 && obj.character[i] == 49)) {

			character[i] = 49;
		}

		else if (character[i] == 49 && obj.character[i] == 49) {

			character[i] = 48;
		}

		else if ((character[i] == 49 && obj.character[i] == 48) || (character[i] == 48 && obj.character[i] == 49)) {

			character[i] = 49;
		}

		else if (character[i] == 49 && obj.character[i] == 49) {

			character[i] = 48;

			if (character[i - 1] == 48 && obj.character[i - 1] == 49) {

				character[i - 1] = 49;
			}

			else if (character[i - 1] == 49 && obj.character[i - 1] == 48) {

				character[i - 1] = 49;
			}

			else if (character[i - 1] == 48 && obj.character[i - 1] == 48) {

				character[i - 1] = 49;
			}
		}
	}

	return *this;
}

Byte Byte::operator -(Byte obj) {

	Byte temp;
	
	return *this;
}

Byte Byte::operator ||(Byte obj) {

	int i = 0;

	while (i < 8) {

		if (character[i] == 49 || obj.character[i] == 49) {

			character[i] = 49;
		}

		else {

			character[i] = 48;
		}

		i++;
	}

	character[i] = '\0';

	return *this;
}

Byte Byte::operator &&(Byte obj) {

	int i = 0;

	while (i < 8) {

		if (character[i] == 49 && obj.character[i] == 49) {

			character[i] = 49;
		}
		else {

			character[i] = 48;
		}

		i++;
	}

	character[i] = '\0';

	return *this;
}

BinaryStore::BinaryStore() {

	bt = '\0';
	address = '\0';
	bs_byte = '\0';
}

BinaryStore::BinaryStore(int n) {

	bt = new char[n * 8];
	address = new char[n * 4];
}

void BinaryStore::Add(char* ptr, Byte obj) {

	int i = 0;

	while (i < 8) {

		bt[i] = obj.character[i];
		i++;
	}

	bt[i] = '\0';
}

char* BinaryStore::getByte() {

	bs_byte = new char[8];

	int i = 0;

	while (i < 8) {

		bs_byte[i] = bt[i];
		i++;
	}

	bs_byte[i] = '\0';

	return bs_byte;
}

void BinaryStore::setSize(int n) {

	bt = new char[n * 8];
	address = new char[n * 4];
}

BinaryStore BinaryStore::operator +=(const char* ptr) {

	int i = 0;
	
	while (i < 4) {

		address[i] += ptr[i];
		i++;
	}

	address[i] = '\0';

	return *this;
}



BinaryStore BinaryStore::Get(char* addressVal) {

	int i = 0;

	while (i < 4) {

		address[i] = addressVal[i];
		i++;
	}

	return *this;
}