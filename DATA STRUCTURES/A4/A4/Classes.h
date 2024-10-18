#pragma once
#include <iostream>
using namespace std;

/*      Muneel Haider
		21i-0640
		Assignment 4    */

struct node {

	int data;
	node* next;
	node* below;

	node(int d = 0) {

		data = d;
		next = NULL;
		below = NULL;
	}
};

struct DList {

	node* head;

	DList() {

		head = NULL;
	}

	void insert(int value) {

		node* temp = new node;
		temp->data = value;
		temp->below = NULL;

		if (head == NULL) {

			head = temp;

			return;
		}

		node* current = head;
		while (current->next != NULL) {

			current = current->next;
		}

		current->next = temp;

		return;
	}

	void insertBelow(int i, int rows, DList* List) {

		node* temp;

		if (i < rows - 1) {

			temp = new node(i + 2);
			List->head->below = temp;
			List->head = List->head->below;
		}
	}

	void print() {

		if (head == NULL) {

			return;
		}
		node* temp = head;
		node* col = head;
		while (col != NULL) {

			temp = col;

			while (temp != NULL) {

				cout << temp->data << " , ";
				temp = temp->next;
			}

			cout << endl << endl;

			col = col->below;
		}
	}


};

struct QuadTreeNode {

    int x1;
    int y1;
    
    int x2;
    int y2;
    
    bool isWhite;
    
    QuadTreeNode* topLeft;
    QuadTreeNode* topRight;
    QuadTreeNode* bottomLeft;
    QuadTreeNode* bottomRight;

	static int counter;

	QuadTreeNode(int xx1 = 0, int yy1 = 0, int xx2 = 0, int yy2 = 0, bool flag = false) {
        
        x1 = xx1;
        y1 = yy1;
        x2 = xx2;
        y2 = yy2;
        isWhite = flag;

        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
};
int QuadTreeNode::counter = 0;

struct QuadTree {

    QuadTreeNode* head;
};