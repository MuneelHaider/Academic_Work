#pragma once
#include <iostream>
using namespace std;

class Matrix {

	float length;
	float width;

public:

	float** matrix = new float* [20];

	Matrix() {

		length = 0;
		width = 0;

		for (int i = 0; i < length; i++) {

			matrix[i] = new float[width];
		}

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {

				matrix[i][j] = 0;
			}
		}
	}

	Matrix(float r, float c) {

		length = r;
		width = c;

		for (int i = 0; i < length; i++) {

			matrix[i] = new float[width];
		}

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {

				matrix[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& obj) {

		this->length = obj.length;
		this->width = obj.width;

		for (int i = 0; i < length; i++) {

			matrix[i] = new float[width];
		}

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {

				matrix[i][j] = obj.matrix[i][j];
			}
		}
	}

	void set(int i, int j, float val) {

		matrix[i][j] = val;
	}
	float get(int i, int j) const {

		return matrix[i][j];
	}

	Matrix& assign(const Matrix& obj) {

		if (this->length == obj.length) {
			if (this->width == obj.width) {

				for (int i = 0; i < length; i++) {
					for (int j = 0; j < width; j++) {

						matrix[i][j] = obj.matrix[i][j];
					}
				}
			}
		}

		return *this;
	}

	Matrix add(const Matrix& obj) {

		if (this->length == obj.length) {
			if (this->width == obj.width) {

				for (int i = 0; i < length; i++) {
					for (int j = 0; j < width; j++) {

						matrix[i][j] += obj.matrix[i][j];
					}
				}
			}
		}
		return *this;
	}

	Matrix subtract(const Matrix& obj) {

		if (this->length == obj.length) {
			if (this->width == obj.width) {

				for (int i = 0; i < length; i++) {
					for (int j = 0; j < width; j++) {

						matrix[i][j] = obj.matrix[i][j] - matrix[i][j];
					}
				}
			}
		}
		return *this;
	}

	Matrix multiply(const Matrix& obj) {

		float** result = new float* [this->length];
		for (int i = 0; i < this->length; i++) {

			result[i] = new float[obj.width];
		}

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < obj.width; j++) {

				result[i][j] = 0;
			}
		}

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < obj.width; j++) {
				for (int k = 0; k < obj.length; k++) {

					result[i][j] += (this->matrix[i][k] * obj.matrix[k][j]);
				}
			}
		}

		this->matrix = result;
		return *this;
	}

	Matrix multiplyElement(const Matrix& obj) {

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < this->width; j++) {

				matrix[i][j] *= obj.matrix[i][j];
			}
		}

		return *this;
	}

	Matrix add(float n) {

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < this->width; j++) {

				matrix[i][j] += n;
			}
		}

		return *this;
	}

	Matrix multiply(float n) {

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < this->width; j++) {

				matrix[i][j] *= n;
			}
		}
		return *this;
	}

	void input() {

		cout << endl << endl << "Taking Inputs:" << endl << endl;
		float number = 0;

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < this->width; j++) {

				cout << "Enter values for matrix[" << i << "][" << j << "] :\t";
				cin >> number;

				matrix[i][j] = number;
			}
		}
	}

	void display() {

		cout << endl << endl << "Display Whole Matrix:" << endl << endl;
		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < this->width; j++) {

				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
};