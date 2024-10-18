#pragma once

class Sandwich {

	char* name = new char;
	char* filling = new char;
	char* size = new char;
	bool is_ready = false;
	double price = 0;

public:

	Sandwich();
	Sandwich(char* fillingVal, double priceVal);
	Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status);
	Sandwich(const Sandwich& sandwich);
	void setFilling(char*);
	void setPrice(double);
	void setName(char*);
	void setSize(char*);
	char* getFilling();
	double getPrice();
	char* getName();
	char* getSize();
	void makeSandwich();
	bool check_status();
};