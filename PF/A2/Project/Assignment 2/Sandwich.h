#pragma once

class Sandwich {

	char* name = new char;
	char* filling = new char;
	char* size = new char;
	bool is_ready = false;
	double price = 0;

public:

	Sandwich() {

	}
	Sandwich(char* fillingVal, double priceVal) {

		filling = fillingVal;
		price = priceVal;
	}
	Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status) {

		filling = fillingVal;
		price = priceVal;
		name = nameVal;
		size = sizeVal;
		is_ready = ready_status;
	}

	Sandwich(const Sandwich& sandwich) {

		filling = sandwich.filling;
		price = sandwich.price;
		name = sandwich.name;
		size = sandwich.size;
		is_ready = sandwich.is_ready;
	}

	void setFilling(char* fillingVal);
	void setPrice(double priceVal);
	void setName(char* nameVal);
	void setSize(char* sizeVal);
	char* getFilling();
	double getPrice();
	char* getName();
	char* getSize();
	void makeSandwich();
	bool check_status();
};