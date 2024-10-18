#pragma once
#include <iostream>
using namespace std;

class Node {

public:

	int data;
	Node* left;
	Node* right;

	Node(int d = 0){
	
		data = d;
		right = NULL;
		left = NULL;
	}
};

class BinarySearchTree {

public:

	Node* root;

	BinarySearchTree() {

		root = NULL;
	}

	void insert(int data) {

		Node* temp = new Node(data);
		Node* current = root;

		if (root == NULL) {

			root = temp;
		}
		else {

			current = root;

			while (root != NULL) {

				if (data < current->data) {

					if (current->left != NULL) {

						current = current->left;
					}
					else {

						current->left = temp;
						break;
					}
				}
				else if (data > current->data) {

					if (current != NULL) {

						current = current->right;
					}
					else {

						current->right = temp;
						break;
					}
				}
				else {

					cout << "DUP";
					break;
				}
			}
		}
	}

	void inOrder() {

		in_order(root);
	}

	void in_order(Node* node) {

		if (node != NULL) {

			in_order(node->left);
			cout << node->data << endl;
			in_order(node->right);
		}
	}

	void preorder(Node* node) {

		if (node != NULL) {

			cout << node->data << endl;
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(Node* node) {

		if (node != NULL) {

			postorder(node->left);
			postorder(node->right);
			cout << node->data << endl;
		}
	}

	void deleteNode(Node* node) {

		Node* temp;

		if (node->left == NULL && node->right == NULL) {

			node = NULL;
			delete node;
		}
		else if (node->right == NULL) {

			temp = node;
			node = node->left;
			delete temp;
			temp = NULL;
		}
		else if (node->left == NULL) {

			temp = node;
			node = node->right;
			delete temp;
			temp = NULL;
		}
		else {

			temp = node->right;

			while (temp->left != NULL) {

				temp = temp->left;
			}

			temp->left = node->left;
			temp = node;
			node = node->right;

			delete temp;
			temp = NULL;
		}
	}

	void RemoveNode(int data, Node* node) {

		if (node == NULL) {

			return;
		}

		if (data < node->data) {

			RemoveNode(data, node->left);
		}
		else if (data > node->data) {

			RemoveNode(data, node->right);
		}
		else {

			deleteNode(node);
		}
	}

	void remove(int d) {

		RemoveNode(d, root);
	}


};