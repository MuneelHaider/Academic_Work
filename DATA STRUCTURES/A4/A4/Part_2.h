#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Classes.h"
#include "Part_3.h"
using namespace std;
using namespace cv;

/*      Muneel Haider
		21i-0640
		Assignment 4    */

void traverseQuadTree(QuadTreeNode* node, bool flag) {

	if (node != NULL) {

		if (flag == false) {

			cout << "Quad Tree Formation. Enter any key to Form Quad Tree." << endl << endl;
			cin.ignore();
			flag = true;
		}

		cout << node->isWhite << endl;

		traverseQuadTree(node->topLeft, flag);
		traverseQuadTree(node->topRight, flag);
		traverseQuadTree(node->bottomLeft, flag);
		traverseQuadTree(node->bottomRight, flag);
	}
}

void fillQuadTree(QuadTreeNode* node, int** array) {
	
	if (node != NULL) {

		int xx1 = node->x1;
		int xx2 = node->x2;
		int t1 = xx1 + xx2;

		int yy1 = node->y1;
		int yy2 = node->y2;
		int t2 = yy1 + yy2;

		bool WhiteCheck = node->isWhite;

		if (WhiteCheck == true) {
		
			for (int i = xx1; i < t1; i++) {
			
				for (int j = yy1; j < t2; j++) {
				
					array[i][j] = 255;
				}
			}
		}
		else {

			for (int i = xx1; i < t1; i++) {
			
				for (int j = yy1; j < t2; j++) {
				
					array[i][j] = 0;
				}
			}
		}

		fillQuadTree(node->topLeft, array);
		fillQuadTree(node->topRight, array);
		fillQuadTree(node->bottomLeft, array);
		fillQuadTree(node->bottomRight, array);
	}
}

void MainOfP2(int** array, int rows, int cols, QuadTree* Tree) {

	fillQuadTree(Tree->head, array);

//	Uncomment if you want to traverse QuadTree
//	traverseQuadTree(Tree->head, true);

	Mat img2(rows, cols, IMREAD_GRAYSCALE);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			img2.at<uchar>(i, j) = (uchar)array[i][j];
		}
	}

	imwrite("D:/Softwares/Visual Studio/DATA STRUCTURES/A4/A4/output3.bmp", img2);

	cout << endl << endl << "Image Written Successfully as 'Output(Picture Number).bmp'." << endl << endl;
	cout << "End of Part 2. Press Any key to proceed to part 3." << endl;
	cin.ignore();
	cin.ignore();

	MainOfP3();
}