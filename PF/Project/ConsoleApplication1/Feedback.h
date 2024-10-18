#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Feedback {

	float rating;
	string review;

public:

	Feedback(float rVal = 0, string reviewVal = "") {

		rating = rVal;
		review = reviewVal;
	}

	void setrating(float rVal) {

		rating = rVal;
	}
	float getrating() {

		return rating;
	}

	void setreview(string rVal) {

		review = rVal;
	}
	string getreview() {

		return review;
	}

	Feedback operator=(Feedback F) {

		this->setrating(F.getrating());
		this->setreview(F.getreview());

		return *this;
	}

};