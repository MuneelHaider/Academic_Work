#pragma once
#include <iostream>
using namespace std;

class Product {

	int quantity;
	static int objCount;
	int serialNo;

public:

	Product(int totalQuantityOfProduct = 0, int serialNumberOfProduct = 0) {
	
		quantity = totalQuantityOfProduct;
		serialNo = serialNumberOfProduct;
	}

	static void incrementProductCount() {

		objCount++;
	}

	int getQuantity() {

		return quantity;
	}
	void setQuantity(int q) {

		quantity = q;
	}

	void setSerial(int s) {

		serialNo = s;
	}
	int getSerial() {

		return serialNo;
	}

	Product operator=(const Product& obj) {

		this->quantity += obj.quantity;
		this->serialNo += obj.serialNo;
		
		return *this;
	}

	Product operator-=(int number) {

		this->quantity -= number;

		return *this;
	}
};

int Product::objCount = 0;