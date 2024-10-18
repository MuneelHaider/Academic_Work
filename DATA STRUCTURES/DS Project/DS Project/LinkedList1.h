#pragma once
#include <iostream>

using namespace std;

template<typename T>
class LNode {

	T data;
	LNode<T>* next = NULL;

public:

	LNode() {}

	LNode(T d) {

		data = d;

	}

	void changeNext(LNode<T>* n) {

		next = n;

	}

	void changeData(T d) {

		data = d;

	}

	LNode<T>* getNext() {

		return next;

	}

	T getData() {

		return data;

	}

	void operator<<(ostream& o) {

		o << data << " ";

	}

};

template<typename T>
class LinkedList {

public:

	LNode<T>* head = NULL;
	int size = 0;


	LinkedList() {

		size = 0;

	}

	void insert(T d) {

		if (size == 0) {

			LNode<T>* newNode = new LNode<T>(d);

			head = newNode;

			size++;

			return;

		}

		LNode<T>* currNode = head;

		while (currNode->getNext() != NULL) {

			currNode = currNode->getNext();

		}

		LNode<T>* newNode = new LNode<T>(d);

		currNode->changeNext(newNode);

		size++;


	}

	void insertAtHead(T d) {

		LNode<T>* newNode = new LNode<T>(d);

		newNode->changeNext(head);

		head = newNode;

		size++;

	}

	T deleteAtHead() {

		if (size == 1) {

			T value = head->getData();
			delete head;
			head = NULL;
			size--;

			return value;

		}

		else {

			T value = head->getData();
			LNode<T>* nextNode = head->getNext();
			delete head;
			head = nextNode;
			size--;

			return value;

		}

	}

	bool isEmpty() {

		if (head == NULL) {

			return true;

		}

		return false;

	}

	LNode<T>* search(T d) {

		if (head == NULL) {

			return NULL;

		}

		LNode<T>* currNode = head;

		if (currNode->getData() == d) {

			return currNode;

		}

		while (currNode->getNext() != NULL) {

			currNode = currNode->getNext();

			if (currNode->getData() == d) {

				return currNode;

			}

		}

	}

	void update(T o, T n) {

		LNode<T>* currNode = search(o);

		currNode->changeData(n);

	}

	bool insertAtIndex(T d, int index) {

		int currIndex = 0;
		LNode<T>* currNode = head;
		LNode<T>* prevNode = NULL;

		if (head == NULL) {

			return false;

		}

		while (currNode->getNext() != NULL && currIndex < index) {

			prevNode = currNode;
			currNode = currNode->getNext();
			currIndex++;

		}

		if (currIndex != index) {

			return false;

		}

		LNode<T>* newNode = new LNode<T>(d);

		if (index == 0) {

			newNode->changeNext(head);
			head = newNode;

		}

		else {

			prevNode->changeNext(newNode);
			newNode->changeNext(currNode);

		}

		size++;

	}

	bool deleteNode(T d) {

		LNode<T>* prevNode = NULL;

		if (head == NULL) {

			return false;

		}

		LNode<T>* currNode = head;

		if (currNode->getData() == d) {

			head = head->getNext();
			size--;
			return true;

		}

		while (currNode->getNext() != NULL) {

			prevNode = currNode;
			currNode = currNode->getNext();

			if (currNode->getData() == d) {

				prevNode->changeNext(currNode->getNext());
				delete currNode;
				size--;
				return true;

			}

		}

	}

	void moveToEnd(T d) {

		LNode<T>* prevNode = NULL;
		LNode<T>* currNode = head;

		if (size == 0 || size == 1) {

			return;

		}

		LNode<T>* nodeToMove = search(d);

		if (nodeToMove == head) {

			head = nodeToMove->getNext();

			while (currNode->getNext() != NULL) {

				currNode = currNode->getNext();

			}

			currNode->changeNext(nodeToMove);
			nodeToMove->changeNext(NULL);

			return;

		}

		if (nodeToMove->getNext() == NULL) {

			return;

		}

		prevNode = NULL;
		currNode = head;

		while (currNode->getData() != nodeToMove->getData()) {

			prevNode = currNode;
			currNode = currNode->getNext();

		}

		prevNode->changeNext(currNode->getNext());

		while (currNode->getNext() != NULL) {

			currNode = currNode->getNext();

		}

		currNode->changeNext(nodeToMove);

		nodeToMove->changeNext(NULL);

		return;


	}

	LNode<T>* getHead() {

		return head;

	}

	void print() {

		LNode<T>* currNode = head;

		if (currNode == NULL) {

			cout << "List is empty";
			return;

		}

		cout << currNode->getData();

		while (currNode->getNext() != NULL) {

			currNode = currNode->getNext();
			cout << currNode->getData();

		}

	}

	int getSize() {

		return size;

	}

};