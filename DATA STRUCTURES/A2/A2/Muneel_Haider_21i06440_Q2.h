#pragma once
#include <iostream>
using namespace std;

// Muneel_Haider_21i0640

void TOPMenu2() {

	system("CLS");
	system("color 3");

	cout << "******************************************" << endl;
	cout << "*					 *" << endl;
	cout << "*	Muneel Haider 21i-0640		 *" << endl;
	cout << "*	Assignment 3 Data Structures	 *" << endl;
	cout << "*					 *" << endl;
	cout << "******************************************" << endl;
	cout << endl << "QUESTION 2";
	cout << endl << endl << endl << endl << endl;
}

class Node {

public:

	const int data; //do not change this
	Node* next;
	Node* prev;

	Node(int d) : data(d)
	{
		next = NULL;
		prev = NULL;
	}
};

class List {

public:

	Node* head;
	Node* tail;
	Node* mid;

	List() {

		head = NULL;
		tail = NULL;
		mid = NULL;
	}

};

void insertionSort(Node*& head, Node*& tail) {

	if (head == NULL || head->next == NULL) {

		return;
	}
	Node* sorted = head;
	Node* current;
	Node* unsorted = head->next;
	
	while (unsorted != NULL) {

		current = unsorted;

		unsorted = unsorted->next;

		if (current->data < sorted->data) {
		
			sorted->next = current->next;
			
			if (current->next != NULL) {
			
				current->next->prev = sorted;
			}
			Node* ptr = sorted;

			while (ptr != NULL && current->data < ptr->data) {
				
				ptr = ptr->prev;
			}

			if (ptr == NULL) {
			
				current->prev = NULL;
				current->next = sorted;
				sorted->prev = current;
				head = current;
			}
			else {
				
				current->prev = ptr;
				current->next = ptr->next;
				ptr->next = current;

				if (current->next != NULL) {
				
					current->next->prev = current;
				}
				else {
					tail = current;
				}
			}
		}
		else {
			sorted = current;
		}
	}
}

void InsertAtEndNode(int d, Node*& head, Node*& tail) {

	Node* temp = new Node(d);

	temp->next = NULL;
	temp->prev = NULL;

	if (head == NULL && tail == NULL) {

		head = temp;
		tail = temp;
	}
	else {

		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

	return;
}

int input(Node*& head, Node*& tail, int no_of_elements) {
	
	int number = 0;

	Node* current = head;
	Node* temp;
	
	cout << " ( Enter any negative number to stop list ) " << endl;

	while (number >= 0) {

		cout << "Enter Number to put into List:\t";
		cin >> number;

		cout << endl;

		if (number >= 0) {
			
			InsertAtEndNode(number, head, tail);
			no_of_elements++;
		}
	}

	return no_of_elements;
}
bool isSorted(Node*& head, Node*& tail) {

	bool flag;
	Node* current = head;

	if (head == NULL) {

		return true;
	}

	while (current != NULL) {

		if (current->next != NULL && (current->data > current->next->data)) {

			return false;
		}

		current = current->next;
	}

	//returns true if the list is sorted
	return true;
}

bool binarySearch(Node* head, Node* tail, Node* mid, int search_number, int numberOfElements) {

	numberOfElements /= 2;

	int counter = 0;

	Node* current = head->next;

	while (counter != numberOfElements) {

		current = current->next;
		counter++;
	}

	mid = current;

	if (current->data == search_number) {

		return true;
	}
	else {

		if (current->data > search_number) {

			while (current->next != NULL) {

				if (current->data == search_number) {

					return true;
				}

				current = current->prev;

				if (current->data == search_number) {

					return true;
				}
			}
		}
		else if (current->data < search_number) {

			while (current->next != NULL) {

				if (current->data == search_number) {

					return true;
				}

				current = current->next;

				if (current->data == search_number) {

					return true;
				}
			}
		}
	}

	return false;
}

void mainOfQuestion2() {

	TOPMenu2();

	Node* head;
	Node* tail;
	Node* mid;
	int no_of_elements = 0;
	int search_number;
	bool flag = false;

	List* all = new List;
	
	//input
	no_of_elements = input(all->head, all->tail, no_of_elements);

	//sort if required
	flag = isSorted(all->head, all->tail);
	
	if (flag == false) {

		insertionSort(all->head, all->tail);
	}

	//input data for search
	
	cout << endl << "Enter number to search:\t";
	cin >> search_number;

	//use binary search
	
	flag = binarySearch(all->head, all->tail, all->mid, search_number, no_of_elements);

	//print output

	if (flag == true) {

		cout << endl << "Yes! Your number has been found in the List." << endl;
	}
	else {

		cout << endl << "No! Unfortunately your required number was not in the List." << endl;
	}
}