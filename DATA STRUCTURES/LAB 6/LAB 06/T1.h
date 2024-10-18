#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node {

public:

	T data;
	Node<T>* next;

	Node() {

		data = 0;
		next = NULL;
	}
	Node(T value) {

		data = value;
		next = NULL;
	}

	T getData() {

		return data;
	}
	T setData(T temp) {

		data = temp;
	}

	Node* getNext() {

		return next;
	}
	void setNext(Node* n) {

		next = n;
	}
};

template <class A>
class SLinkedList {

public:

	Node<A>* head;

	SLinkedList() {

		head = NULL;
	}

	/*********************************/

	void insert(A value) {

		Node<A>* node = new Node<A>;
		node->data = value;

		if (head == NULL) {

			head = node;

			return;
		}

		Node<A>* temp = head;

		while (temp->next != NULL) {

			temp = temp->next;
		}

		temp->next = node;

		return;
	}

	void insertAtHead(A value) {

		Node<A>* node = new Node<A>;
		node->data = value;

		if (head == NULL) {

			head = node;

			return;
		}
		
		node->next = head;
		head = node;

		return;
	}

	void InsertAtIndex(A value, int index) {

		if (index < 0) {

			return;
		}

		Node<A>* node = new Node<A>;

		node->data = value;

		int counter = 0;

		Node<A>* temp = head;

		while (temp != NULL && counter < index) {

			if (counter == index - 1) {

				if (temp->next != NULL) {

					node->next = temp->next;
				}
				
				temp->next = node;

				return;
			}

			counter++;
			temp = temp->next;
		}

		return;
	}



	void remove(A index) {
		Node<A>* currNode = new Node<A>;
		currNode = head;
		int currIndex = 1;
		while ((currIndex) < index) {
			currNode = currNode->next;
			currIndex++;
		}
		
		Node<A>* temp = new Node<A>;
		temp = currNode->next;
		currNode->next = currNode->next->next;

		delete temp;

	}

	void print() {
		if (head == NULL) {
		
			return;
		}
		Node<A>* temp = head;
		while (temp != NULL) {
			
			temp = temp->next;
		}
	}

};