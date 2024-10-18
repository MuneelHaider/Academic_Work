#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Classes.h"
using namespace std;
using namespace cv;

/*      Muneel Haider
		21i-0640
		Assignment 4    */

int** ReadingOriginalFile(int& rows, int& cols) {

	// Enter your Path
	Mat img = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/A4/Student Test Images/t3.bmp", IMREAD_GRAYSCALE);

	if (img.empty()) {

		cout << "Could not open Image." << endl;
		return NULL;
	}

	int** array = new int* [img.rows];
	for (int i = 0; i < img.rows; i++) {

		array[i] = new int[img.cols];
	}

	for (int i = 0; i < img.rows; i++) {

		for (int j = 0; j < img.cols; j++) {

			array[i][j] = (int)img.at<uchar>(i, j);
		}
	}

	rows = img.rows;
	cols = img.cols;

	return array;
}

int** ReadingOutputFile() {

	// Enter your Path
	Mat img = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/A4/A4/output3.bmp", IMREAD_GRAYSCALE);

	if (img.empty()) {

		cout << "Could not open Image." << endl;
		return NULL;
	}

	int** array = new int* [img.rows];
	for (int i = 0; i < img.rows; i++) {

		array[i] = new int[img.cols];
	}

	for (int i = 0; i < img.rows; i++) {

		for (int j = 0; j < img.cols; j++) {

			array[i][j] = (int)img.at<uchar>(i, j);
		}
	}

	return array;
}

void MainOfP3() {

	int rows = 0;
	int cols = 0;

	int** array = ReadingOriginalFile(rows, cols);

	int** demo = ReadingOutputFile();

	float Value_of_x = 0;
	float temp = 0;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			temp += ((array[i][j] - demo[i][j]) * (array[i][j] - demo[i][j]));
		}
	}

	Value_of_x = (temp / (rows * cols));

	temp = Value_of_x / (255 * 255);
	
	float temp1 = 1 - temp;

	float Value_of_Y = 100 * temp1;

	cout << endl << "Accuracy:\t" << Value_of_Y << endl << endl;

	return;
}