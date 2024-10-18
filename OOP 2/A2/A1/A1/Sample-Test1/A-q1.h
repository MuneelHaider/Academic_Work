#pragma once
#include <iostream>
using namespace std;


class Invoice {
private:

	char* partNum;
	char* partDesc;
	int quantity;
	float pricePerItem;


	
public:

	Invoice() {

		partNum = '\0';
		partDesc = '\0';
		quantity = 0;
		pricePerItem = 0;

	}


	Invoice(char* pn, char* pd, int q, float pp) {


		if (q < 0) {
			q = 0;
		}
		if (pp < 0) {
			pp = 0;
		}

		partNum = pn;
		partDesc = pd;
		quantity = q;
		pricePerItem = pp;


	}


	Invoice(int q, float pp) {

		if (q < 0) {
			q = 0;
		}
		if (pp < 0) {
			pp = 0;
		}

		quantity = q;
		pricePerItem = pp;
		partNum = '\0';
		partDesc = '\0';

		

	}


	Invoice(Invoice& i) {

		quantity = i.quantity;
		pricePerItem = i.pricePerItem;
		partNum = i.partNum;
		partDesc = i.partDesc;

	} // copy constructor



	//implement mutators for all private data members
	//implement accessors for all private data members
	//you have to implement the following functions as well

		char* getPartNum() {
			return partNum;
		}

		void setPartNum(char *pn) {
			partNum = pn;
		}

		char* getPartDesc() {
			return partDesc;
		}

		void setPartDesc(char *pd) {
			partDesc = pd;
		}

		int getQuantity() {
			return quantity;
		}

		void setQuantity(int Quantity) {

			if (Quantity < 0) {
				Quantity = 0;
				
			}	

			quantity = Quantity;
		}

		float getPricePerItem() {
			return pricePerItem;
		}

		void setpriceitem(int priceperitem) {
			
			if (priceperitem < 0) {
				priceperitem = 0;
			}

			pricePerItem = priceperitem;
		}

			
	float getInvoiceAmount();
	~Invoice() {


	}
	
};





float Invoice :: getInvoiceAmount() {
	float invoiceamount = 0;


	invoiceamount = quantity * pricePerItem;

	return invoiceamount;


}