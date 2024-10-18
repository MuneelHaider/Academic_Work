#pragma once
#include <iostream>
using namespace std;

class Invoice {

	char* partNum;
	char* partDesc;
	int quantity;
	float pricePattern;

public:

	Invoice() {

		partNum = " ";
		partDesc = " ";
		quantity = 0;
		pricePattern = 0.0;
	}

	Invoice(int q, float p) {

		partNum = " ";
		partDesc = " ";
		quantity = q;
		pricePattern = p;
	}

	Invoice(char* partN, char* partD, int q = 0, float priceP = 0) {

		partNum = partN;
		partDesc = partD;
		quantity = q;
		pricePattern = priceP;
	}

	Invoice(Invoice& obj) {

		this->partNum = obj.partNum;
		this->partDesc = obj.partDesc;
		this->quantity = obj.quantity;
		this->pricePattern = obj.pricePattern;
	}

	char* getPartNum() {

		return this->partNum;
	}
	void setPartNum(char* n) {

		partNum = n;
	}

	char* getPartDesc() {

		return this->partDesc;
	}
	void setPartDesc(char* d) {

		partDesc = d;
	}

	int getQuantity() {

		if (quantity < 0) {

			quantity = 0;
		}

		return quantity;
	}
	void setQuantity(int q) {

		quantity = q;
	}

	float getPricePerItem() {

		if (pricePattern < 0) {

			pricePattern = 0;
		}

		return pricePattern;
	}
	void setPricePerItem(float p) {

		pricePattern = p;
	}

	float getInvoiceAmount();
};

float Invoice::getInvoiceAmount() {

	float result = 0.0;

	if (this->quantity < 0) {

		this->quantity = 0;
	}
	if (this->pricePattern < 0) {

		this->pricePattern = 0;
	}

	result = this->quantity * this->pricePattern;

	return result;
}