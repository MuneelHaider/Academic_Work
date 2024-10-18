#pragma once
#include<iostream>
using namespace std;

/*		Muneel Haider		
		21i-0640
		LAB 9				
		Question 1			*/	

template<typename M>
class node {

public:

	int val;
	node<M>* next;
	
	node(int V) {

		val = V;
		next = NULL;
	}
};

template<typename M>
class stack {

public:

	node<M>* top;
	int count;
	
	stack(int d = 0) {

		count = 0;
		top = NULL;
	}

	void push(int val) {

		node<M>* temp = new node<M>(val);
		
		temp->next = top;
		top = temp;
		count++;
	}

	bool IsEmpty() {

		if (top == NULL)
			return true;

		return false;
	}

	int pop() {

		if (!IsEmpty()) {

			node<M>* temp = top;
			
			int data = temp->val;
			top = top->next;

			delete temp;
			count--;

			return data;
		}

	}

	node<M>* Peek() {

		return top;
	}

	void Clear() {

		while (top != NULL) {

			top->val = 0;
			top = top->next;
		}
	}
	int size() {

		return count;
	}
};