#pragma once
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include <string>

using namespace std;

template<class S>
S maxfinder(S a,S b) {

	if (a > b) {

		return a;

	}

	return b;
}

template<class R>
struct bstNode {

	R data;
	LinkedList<string> location;
	string filename;
	bstNode<R>* right = NULL;
	bstNode<R>* left = NULL;
	int height = 1;

public:

	bstNode() {}

	bstNode(R d) {

		data = d;

	}

	void changeRight(bstNode<R>* n) {

		right = n;

	}


	void changeLeft(bstNode<R>* n) {

		left = n;

	}

	void changeData(R d) {

		data = d;

	}

	bstNode<R>* getRight() {

		return right;

	}

	bstNode<R>* getLeft() {

		return left;

	}

	R getData() {

		return data;

	}

	bool hasNoChild() {

		if (left == NULL && right == NULL) {

			return false;

		}

		return true;

	}

	int getHeight() {

		return height;

	}

	void setHeight(int h) {

		height = h;

	}

};


template<class T>
class BST {

	bstNode<T>* root = NULL;
	int totalNodes = 0;
	int height = 0;

public:

	BST() {}

	void changeRoot(bstNode<T>* node) {

		root = node;

	}

	int getHeight(bstNode<T>* n) {

		if (n == NULL) {

			return 0;

		}

		return n->height;

	}

	bstNode<T>* deleteN(T key) {

		totalNodes--;
		return root = deleteNode(root, key);

	}

	bstNode<T>* deleteNode(bstNode<T>* n, T key) {

		if (n == NULL) {

			return n;

		}

		if (key < n->data) {

			n->left = deleteNode(n->left, key);

		}

		else if (key > n->data) {

			n->right = deleteNode(n->right, key);

		}

		else if (key == n->data) {

			if (n->left == NULL && n->right == NULL) {

				n = NULL;

			}

			else if (n->right == NULL) {

				n = n->left;

			}

			else if (n->left == NULL) {

				n = n->right;

			}

			else {

				bstNode<T>* inOrderSuccesor = n->right;

				while (inOrderSuccesor->left) {

					inOrderSuccesor = inOrderSuccesor->left;

				}

				n->data = inOrderSuccesor->data;

				n->right = deleteNode(n->right, inOrderSuccesor->data);

			}

		}

		if (n == NULL) {

			return n;

		}

		n->height = 1 + maxfinder(getHeight(n->left), getHeight(n->right));

		int balance = calculateBalance(n);

		if (balance != 0) {

			if (balance > 1 && calculateBalance(root->left) >= 0) {

				return rightRotation(n);

			}

			if (balance < -1 && calculateBalance(root->right) <= 0) {

				return leftRotation(n);

			}

			if (balance > 1 && calculateBalance(root->left) < 0) {

				n->left = leftRotation(n->left);
				return rightRotation(n);

			}

			if (balance < -1 && calculateBalance(root->right) > 0) {

				n->right = rightRotation(n->right);
				return leftRotation(n);

			}

		}

		return n;


	}

	bstNode<T>* newNode(T key) {

		bstNode<T>* newNode = new bstNode<T>(key);

		return newNode;

	}

	bstNode<T>* insertInternal(bstNode<T>* n, T key) {

		if (n == NULL) {

			return newNode(key);

		}

		if (n->getData() > key) {

			n->left = insertInternal(n->left, key);

		}

		else if (n->getData() < key) {

			n->right = insertInternal(n->right, key);

		}

		n->height = 1 + maxfinder(getHeight(n->left), getHeight(n->right));

		int balance = calculateBalance(n);

		if (balance != 0) {

			if (balance > 1 && key < n->left->data) {

				return rightRotation(n);

			}

			if (balance < -1 && key > n->right->data) {

				return leftRotation(n);

			}

			if (balance > 1 && key > n->left->data) {

				n->left = leftRotation(n->left);
				return rightRotation(n);

			}

			if (balance < -1 && key < n->right->data) {

				n->right = rightRotation(n->right);
				return leftRotation(n);

			}

		}

		return n;

	}

	bstNode<T>* insert(T d) {

		root = insertInternal(root, d);
		totalNodes++;
		return root;

	}

	int calculateBalance(bstNode<T>* node) {

		if (node == NULL) {

			return 0;

		}

		else {

			return getHeight(node->left) - getHeight(node->right);

		}

	}

	bool retrieve(T d) {

		bstNode<T>* tempNode = NULL;
		bstNode<T>* currNode = root;

		height = 0;

		while (currNode) {

			if (d > currNode->getData()) {

				tempNode = currNode;
				currNode = currNode->getRight();
				height++;

			}

			else if (d < currNode->getData()) {

				tempNode = currNode;
				currNode = currNode->getLeft();
				height++;

			}

			else if (d == currNode->getData()) {

				return true;

			}

		}

		return false;

	}

	void displayInOrder() {

		inOrderTraversal(root);

	}

	void inOrderTraversal(bstNode<T>* root) {

		if (root == NULL) {

			return;

		}

		inOrderTraversal(root->getLeft());

		cout << root->getData() << ":" << root->height << endl;

		inOrderTraversal(root->getRight());

	}

	void displayPreOrder() {

		preOrderTraversal(root);

	}

	void preOrderTraversal(bstNode<T>* root) {

		if (root == NULL) {

			return;

		}

		ofstream fout(root->filename);

		if (root->left != NULL) {

			fout << root->left->filename << endl;

		}

		else {

			fout << endl;

		}

		if (root->right != NULL) {

			fout << root->right->filename << endl;

		}

		else {

			fout << endl;

		}

		LNode<string>* temp = new LNode<string>();
		temp = root->location.getHead();

		for (int i = 0; i < root->location.getSize(); i++) {

			fout << temp->getData() << endl;

			temp = temp->getNext();

		}

		//cout << node->location << "*" << node->left->filename << "*" << node->right->filename << endl;
		//cout << node->filename << endl;
		fout.close();

		preOrderTraversal(root->getLeft());

		preOrderTraversal(root->getRight());

	}

	void displayPostOrder(T num1, T num2) {

		postOrderTraversal(root, num1, num2);

	}

	void postOrderTraversal(bstNode<T>* root, T num1, T num2) {

		if (root == NULL) {

			return;

		}

		LinkedList<string> l = root->location;
		LNode<string>* lol = l.getHead();
		string location = "";
		string filename = "";
		int lineNum = -1;
		string temp = "";
		int countedStuff = 0;
		string data = "";

		if (root != NULL) {

			for (int i = 0; i < l.getSize(); i++) {

				if (root->data >= num1 && root->data <= num2) {

					location = lol->getData();

					//cout << location << endl;

					countedStuff = 0;

					for (int j = 0; j < location.length(); j++) {

						if (location[j] != ',') {

							temp += location[j];

						}

						else {

							if (countedStuff == 0) {

								filename = temp;
								temp = "";
								countedStuff++;

							}

						}

					}

					lineNum = stoi(temp);

					temp = "";

					lol = lol->getNext();

					ifstream fin(filename);

					for (int i = 0; i < lineNum; i++) {

						getline(fin, data);

					}

					cout << data << endl;

					fin.close();

				}

			}

		}

		postOrderTraversal(root->getLeft(), num1, num2);

		postOrderTraversal(root->getRight(), num1, num2);

	}

	bstNode<T>* rightRotation(bstNode<T>* rootn) {

		bstNode<T>* temp = rootn->left;
		bstNode<T>* temp2 = temp->right;

		temp->right = rootn;
		rootn->left = temp2;

		rootn->height = maxfinder(getHeight(rootn->left), getHeight(rootn->right)) + 1;
		temp->height = maxfinder(getHeight(temp->left), getHeight(temp->right)) + 1;

		return temp;

	}

	bstNode<T>* leftRotation(bstNode<T>* rootn) {

		bstNode<T>* temp = rootn->right;
		bstNode<T>* temp2 = temp->left;

		temp->left = rootn;
		rootn->right = temp2;

		rootn->height = maxfinder(getHeight(rootn->left), getHeight(rootn->right)) + 1;
		temp->height = maxfinder(getHeight(temp->left), getHeight(temp->right)) + 1;

		return temp;

	}

	bstNode<T>* search(T d) {
		if (root == NULL) {
			return root;
		}
		else {
			bstNode<T>* temp = root;
			while (temp != NULL) {
				if (d == temp->getData()) {
					//return temp;
					return temp;
				}
				else if (d < temp->getData()) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			return NULL;
		}
	}

};
