#pragma once
#include <iostream>
using namespace std;

struct Node {

	int data;
	Node* right;
	Node* left;

	Node() {

		data = 0;
		right = NULL;
		left = NULL;
	}
	Node(int d, Node* r = NULL, Node* l = NULL) {

		data = d;
		right = NULL;
		left = NULL;
	}
};

int countNodes(Node* root) {

	if (root == NULL) {

		return 0;
	}

	return countNodes(root->left) + countNodes(root->right) + 1;
}
