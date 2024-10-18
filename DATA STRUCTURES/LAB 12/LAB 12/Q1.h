#pragma once
#include <iostream>
using namespace std;

struct TreeNode {

	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d = 0) {

		data = d;
		left = NULL;
		right = NULL;
	}

};

struct BinarySearchTree {

	TreeNode* root;

	BinarySearchTree() {

		root = NULL;
	}

	void inOrder() {

		in_order(root);
	}

	void in_order(TreeNode* ptr) {

		if (ptr != NULL) {

			in_order(ptr->left);
			cout << ptr->data << " ";
			in_order(ptr->right);
		}
	}
	
	void insert(int d) {

		TreeNode* temp = new TreeNode;
		temp->left = NULL;
		temp->right = NULL;
		TreeNode* ptr;
		temp->data = d;
		
		if (root == NULL) {

			root = temp;
		}
		else {

			ptr = root;
			while (root != NULL) {

				if (d < ptr->data) {

					if (ptr->left != NULL) {

						ptr = ptr->left;
					}
					else {

						ptr->left = temp;
						break;
					}
				}
				else if (d > ptr->data) {

					if (ptr->right != NULL) {

						ptr = ptr->right;
					}
					else {

						ptr->right = temp;
						break;
					}
				}
				else {

					cout << "Duplicate value in Tree" << endl;
					break;
				}
			}
		}
	}

	void remove(int d) {

		RemoveNode(d, root);
	}

	void deleteNode(TreeNode* ptr) {

		TreeNode* temp;

		if (ptr->right == NULL && ptr->left == NULL) {

	//		ptr->data = 100;
			/*ptr = NULL;
			delete ptr;*/
			free(ptr);
		}

		else if (ptr->right == NULL) {

			temp = ptr;
			ptr = ptr->left;
			delete temp;
			temp = NULL;
		}
		else if (ptr->left == NULL) {

			temp = ptr;
			ptr = ptr->right;
			delete temp;
			temp = NULL;
		}
		else {

			temp = ptr->right;

			while (temp->left != NULL) {

				temp = temp->left;
			}

			temp->left = ptr->left;
			temp = ptr;
			ptr = ptr->right;

			delete temp;
			temp = NULL;
		}
	}

	void RemoveNode(int d, TreeNode* ptr) {

		if (ptr == NULL) {

			cout << d << " is not found." << endl;
		}
		else if (d < ptr->data) {

			RemoveNode(d, ptr->left);
		}
		else if (d > ptr->data) {

			RemoveNode(d, ptr->right);
		}
		else {

			deleteNode(ptr);
			ptr = NULL;
		}
	}



};