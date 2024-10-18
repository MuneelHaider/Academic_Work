#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>
#include "Classes.h"
#include "Part_2.h"
using namespace std;
using namespace cv;

/*      Muneel Haider
		21i-0640
		Assignment 4    */

void Convert_A_to_2DLL(DList* List, int** array, int rows, int cols) {

	List->insert(1);

	int counter = 0;
	node* main = List->head;
	node* temp;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			if (array[i][j] == 255) {

				List->insert(++j);

				for (counter; array[i][j] == 255; j++) {}

				List->insert(j);
			}
		}

		List->insert(-2);

		for (int j = 0; j < cols; j++) {

			if (array[i][j] == 0) {

				List->insert(++j);

				for (counter; array[i][j] == 0; j++) {}

				List->insert(j);
			}
		}

		List->insert(-1);

		List->insertBelow(i, rows, List);
	}

	List->head = main;
}

int indexer = 0;
bool ArrayColorCheck(int** array, int x1, int y1, int x2, int y2) {

	int index = array[x1][y1];
	int l1 = x1 + x2;
	int l2 = y1 + y2;

	for (int i = x1; i < l1; i++) {
	
		for (int j = y1; j < l2; j++) {
		
			if (array[i][j] != index) {
			
				return false;
			}
		}
	}

	return true;
}

QuadTreeNode* MakeQuadTree(int** array, int x1, int y1, int x2, int y2) {
	
	bool isWhite = false;
	bool check = ArrayColorCheck(array, x1, y1, x2, y2);

	if (check == true) {

		if (array[x1][y1] == 255) {

			isWhite = true;
		}
		else{
			
			isWhite = false;
		}

		QuadTreeNode* temp = new QuadTreeNode(x1, y1, x2, y2, isWhite);

		return temp;
	}
	
	int half_x2 = x2 / 2;
	int half_y2 = y2 / 2;
	
	QuadTreeNode* topLeft = MakeQuadTree(array, x1, y1, half_x2, half_y2);
	QuadTreeNode* topRight = MakeQuadTree(array, x1, y1 + half_y2, half_x2, half_y2);
	QuadTreeNode* bottomLeft = MakeQuadTree(array, x1 + half_x2, y1, half_x2, half_y2);
	QuadTreeNode* bottomRight = MakeQuadTree(array, x1 + half_x2, y1 + half_y2, half_x2, half_y2);
	
	QuadTreeNode* node = new QuadTreeNode(x1, y1, x2, y2, isWhite);
	
	node->topLeft = topLeft;
	node->topRight = topRight;
	node->bottomLeft = bottomLeft;
	node->bottomRight = bottomRight;
	return node;
}

void writeQuadTreeToFile(QuadTreeNode* node, bool flag) {

	string filename;

	if (node == NULL) {

		return;
	}

	if (flag == false) {

		filename = "D:/Softwares/Visual Studio/DATA STRUCTURES/A4/A4/Nodes/root.txt";
		flag = true;
	}
	else {
		
		filename = "D:/Softwares/Visual Studio/DATA STRUCTURES/A4/A4/Nodes/quadtree_node_";
		filename += to_string(indexer);
		filename += ".txt";

		indexer++;
	}


	ofstream file(filename);
	
	if (!file.is_open()) {

		cout << "Writing error. Filename:\t" << filename << endl << endl;
		
		return;
	}

	// File will be written as X, Y, x2, y2, isWhite boolean
	file << node->x1 << "," << node->y1 << "," << node->x2 << "," << node->y2 << "," << node->isWhite << endl;

	writeQuadTreeToFile(node->topLeft, flag);
	writeQuadTreeToFile(node->topRight, flag);
	writeQuadTreeToFile(node->bottomLeft, flag);
	writeQuadTreeToFile(node->bottomRight, flag);
}

void mainOfP1() {

	Mat img = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/A4/Student Test Images/t2.bmp", IMREAD_GRAYSCALE);

	if (img.empty()) {

		cout << "Could not open Image." << endl;
		return;
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

	cout << endl << endl;
	cout << "Rows of Selected Image:\t\t" << img.rows << endl;
	cout << "Columns of Selected Img:\t" << img.cols << endl;


	/***************************************/

	DList DLL;

	Convert_A_to_2DLL(&DLL, array, img.rows, img.cols);

	// Uncomment if you want to Traverse the 2D Linked List
	 DLL.print();

	/***************************************/

	QuadTree Tree;

	Tree.head = MakeQuadTree(array, 0, 0, img.rows, img.cols);

	/***************************************/

	

	QuadTreeNode* current = Tree.head;

	// Uncomment if you want to traverse QuadTree
	// traverseQuadTree(current, true);

	writeQuadTreeToFile(Tree.head, false);

	/***************************************/

	cout << endl << endl << "Nodes written into different files successfully." << endl;
	cout << "Root Node Created." << endl;
	cout << endl << endl << "End of Part 1." << endl;
	cout << "Press any key to proceed to Part 2" << endl;
	cin.ignore();

	MainOfP2(array, img.rows, img.cols, &Tree);
}