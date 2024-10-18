#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node {

	int data;
	Node* left;
	Node* right;

	Node() {

		data = 0;
		left = NULL;
		right = NULL;
	}

	Node(int d) {

		data = d;
		left = NULL;
		right = NULL;
	}

};

Node* createNode(int d) {

	Node* temp = new Node;
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void deleteTree(Node* ptr) {

	ptr = NULL;
}

void inOrderTraversal(Node* ptr) {

	if (ptr != NULL) {

		inOrderTraversal(ptr->left);
		cout << ptr->data << " ";
		inOrderTraversal(ptr->right);
	}
}

void preOrderTraversal(Node* ptr) {

	if (ptr != NULL) {

		cout << ptr->data << " ";
		preOrderTraversal(ptr->left);
		preOrderTraversal(ptr->right);
	}
}

void postOrderTraversal(Node* ptr) {

	if (ptr != NULL) {

		postOrderTraversal(ptr->left);
		postOrderTraversal(ptr->right);
		cout << ptr->data << " ";
	}
}