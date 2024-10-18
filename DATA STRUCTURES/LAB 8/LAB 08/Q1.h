#pragma once
#include <iostream>
using namespace std;

class Node {

public:

	int data;
	Node* next;

	Node(int d = 0) {

		data = d;
		next = NULL;
	}

	int getData() {

		return data;
	}
	Node* getNext() {

		return next;
	}
};

template <class L>
class Queue {

public:

	Node* front;
	Node* rear;

	Queue() {

		front = NULL;
		rear = NULL;
	}

	int Front() {

		return front->data;
	}
	Node* getRear() {

		return rear;
	}

	void enqueue(int d) {

		insertAtEnd(d);
	}

	int dequeue() {

		Node* temp = front;
		front = front->next;

		return temp->data;
	}

	void insertAtStart(int d) {

		Node* temp = new Node(d);

		front = temp;
		rear = temp;
	}

	void insertAtEnd(int d) {

		if (front == NULL && rear == NULL) {

			insertAtStart(d);
		}

		Node* temp = new Node(d);
		rear->next = temp;
		temp->next = front;
		rear = temp;
	}

	bool isEmpty() {

		if (front == rear || front == NULL || rear == NULL) {

			return true;
		}

		return false;
	}

};

void roundRobin(Queue<int> obj, int d) {

	Node* current = obj.front;
	Node* end = obj.rear;

	while (current != obj.rear) {

		cout << endl << "Execution Time: " << d << endl;
		cout << "This Time: " << current->data << endl;
		current->data -= d;

		cout << endl << "Remaining Time: " << current->data << endl;

		obj.dequeue();

		if (current->data > 0) {

			cout << "Task is being re-scheduled." << endl;

			obj.enqueue(current->data);
		}
		else {

			cout << "Task is completed." << endl;
		}
		current = current->next;
	}
}