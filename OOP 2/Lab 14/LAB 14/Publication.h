#pragma once
#include <iostream>
using namespace std;

class Publication {

	string title;
	float price;

public:

	Publication(string t = "", float p = 0) {

		title = t;
		price = p;
	}

	void setTitle(string t) {

		title = t;
	}
	string getTitle() {

		return title;
	}

	void setPrice(float p) {

		price = p;
	}
	float getPrice() {

		return price;
	}

	void display() {

		cout << "Title:\t" << title << endl;
		cout << "Price:\t" << price << endl;
	}

	~Publication(){}
};

class book : Publication {

	int pageCount;

public:

	book(int pC = 0, string t = "", float p = 0) {

		setTitle(t);
		setPrice(p);
		pageCount = pC;
	}

	void setPageCount(int p) {

		pageCount = p;
	}
	int getPageCount() {

		return pageCount;
	}

	void display() {

		Publication temp("Mr. Monroe", 100);
		temp.display();
		cout << endl << "Page Count:\t" << pageCount << endl;
	}

	~book(){}
};

class tape : Publication {

	float type;

public:

	tape(float tp = 0, string t = "", float p = 0) {
	
		type = tp;
		setTitle(t);
		setPrice(p);
	}

	void setType(float t) {

		type = t;
	}
	float getType() {

		return type;
	}

	void display() {

		Publication::display();
		cout << endl << "Type:\t" << type << endl;
	}

	~tape(){}
};