#pragma once
#include <iostream>
using namespace std;

class Node {

public:

	int data;
	Node* left;
	Node* right;
	int height;
	
	Node(int d = 0, int h = 0) {

		data = d;
		height = h;
		right = NULL;
		left = NULL;
	}
};
class AVLTree {

public:

	Node* root;

	AVLTree() {

		root = NULL;
	}

	int getheight(Node* current) {

		if (current != NULL) {

			return current->height;
		}
		else {

			return 0;
		}
	}

	int balancefactor(Node* node) {

		if (node != NULL) {

			return getheight(node->left) - getheight(node->right);
		}
		else {

			return 0;
		}
	}

	/*Node* leftrotate(Node* node) {

		Node* temp1 = node->right;
		Node* temp2 = temp1->left;

		temp1->left = node;
		node->right = temp2;

		node->height = max(getheight(node->left), getheight(node->right)) + 1;
		temp1->height = max(getheight(temp1->left), getheight(temp1->right)) + 1;
	
		return temp1;
	}

	Node* rightrotate(Node* node) {

		Node* temp1 = node->left;
		Node* temp2 = temp1->right;

		temp1->right = node;
		node->left = temp2;

		temp1->height = max(getheight(temp1->left), getheight(temp1->right)) + 1;
		node->height = max(getheight(node->left), getheight(node->right)) + 1;
		
		return node;
	}*/

	/*Node* insert(Node* node, int data) {

		if (node == NULL) {

			return new Node(data);
		}

		if (data < node->data) {

			node->left = insert(node->left, data);
		}
		if (data > node->data) {

			node->right = insert(node->right, data);
		}
		else {

			return node;
		}

		node->height = max(getheight(node->left), getheight(node->right)) + 1;

		int balance = balancefactor(node);

		if (balance > 1) {

			if (data < node->left->data) {

				return rightrotate(node);
			}
			else {

				node->left = leftrotate(node->left);
				return rightrotate(node);
			}
		}
		
		if (balance < -1) {

			if (data > node->right->data) {

				return leftrotate(node);
			}
			else {

				node->right = rightrotate(node->right);
				return leftrotate(node);
			}
		}

		return node;
	}*/

	bool search(Node* current, int d) {

		if (current == NULL) {

			return false;
		}

		if (d < current->data) {

			return search(current->left, d);
		}
		else if (d > current->data) {

			return search(current->right, d);
		}

		return true;
	}

	Node* leftrotate(Node* node) {

		Node* temp1 = node->right;
		Node* temp2 = temp1->left;

		temp1->left = node;
		node->right = temp2;

		node->height = max(getheight(node->left), getheight(node->right)) + 1;
		temp1->height = max(getheight(temp1->left), getheight(node->right)) + 1;

		return temp1;
	}

	Node* rightrotate(Node* node) {

		Node* temp1 = node->left;
		Node* temp2 = temp1->right;

		temp1->right = node;
		node->left = temp2;

		temp1->height = max(getheight(temp1->left), getheight(temp1->right)) + 1;
		node->height = max(getheight(node->left), getheight(node->right)) + 1;

		return node;
	}

	Node* insert(Node* node, int data) {

		if (node == NULL) {

			return new Node(data);
		}

		if (data < node->data) {

			node->left = insert(node->left, data);
		}
		else if (data > node->data) {

			node->right = insert(node->right, data);
		}
		else {

			return node;
		}

		node->height = max(getheight(node->left), getheight(node->right)) + 1;

		int balance = balancefactor(node);

		if (balance > 1) {

			if (data < node->left->data) {

				return rightrotate(node);
			}
			else {

				node->left = leftrotate(node->left);
				return rightrotate(node);
			}
		}
		
		if (balance < -1) {

			if (data < node->right->data) {

				return leftrotate(node);
			}
			else {

				node->right = rightrotate(node->right);
				return leftrotate(node);
			}
		}

		return node;
	}

};