#pragma once
#include <iostream>
using namespace std;

// Muneel_Haider_21i0640

void TOPMenu1() {

	system("CLS");
	system("color 3");

	cout << "******************************************" << endl;
	cout << "*					 *" << endl;
	cout << "*	Muneel Haider 21i-0640		 *" << endl;
	cout << "*	Assignment 3 Data Structures	 *" << endl;
	cout << "*					 *" << endl;
	cout << "******************************************" << endl;
	cout << endl << "QUESTION 1";
	cout << endl << endl << endl << endl << endl;
}

class student_Node {

public:

	string data;
	student_Node* next;

	student_Node(string data) {
		this->data = data;
		this->next = NULL;
	}
};
//The above portion cannot be changed

class LinkedList {

public:

	student_Node* head;

	LinkedList() {

		head = NULL;
	}

	void createAfterHead() {

		student_Node* temp = new student_Node("");

		head = temp;
		head->next = temp;
	}

	void Fill_fgc() {

		string name;

		while (name[0] != '0') {

			cout << "Enter FGC student name:\t";
			getline(cin, name);
			cout << endl;

			if (name[0] == 'm') {

				return;
			}

			student_Node* temp = new student_Node(name);

			InsertAtEnd(name);
		}
	}

	void Fill_fas() {

		string name;

		while (name[0] != '0') {

			cout << "Enter FAS student name:\t";
			getline(cin, name);
			cout << endl;

			if (name[0] == 'm') {

				return;
			}

			student_Node* temp = new student_Node(name);

			InsertAtEnd(name);
		}
	}

	void Fill_fds() {

		string name;

		while (name[0] != '0') {

			cout << "Enter FDS student name:\t";
			getline(cin, name);
			cout << endl;

			if (name[0] == 'm') {

				return;
			}

			student_Node* temp = new student_Node(name);

			InsertAtEnd(name);
		}
	}

	void insertAtStart(student_Node* node) {

		student_Node* temp = new student_Node("");
		
		temp->data = node->data;

		temp->next = NULL;

		if (head == NULL) {

			head = temp;
		}
		else {

			temp->next = head;
			head = temp;
		}

		temp = NULL;
		delete temp;

		return;
	}

	void InsertAtEnd(string d) {

		student_Node* temp = new student_Node("");

		temp->data = d;

		temp->next = NULL;

		student_Node* current = head;

		if (head == NULL) {

			head = temp;
		}
		else {

			while (current->next != NULL) {

				current = current->next;
			}

			current->next = temp;
		}
		temp = NULL;

		delete temp;

		return;
	}

};

string* list_of_all_students(student_Node* head1, student_Node* head2, student_Node* head3)
{
	string* result;
	//enter your code here

	LinkedList* all = new LinkedList;

	student_Node* current = all->head;
	student_Node* h1 = head1;
	student_Node* h2 = head2;
	student_Node* h3 = head3;

	bool flag = false;

	// Inserting FGC List into ALL List
	while (h1 != NULL) {

		all->InsertAtEnd(h1->data);

		h1 = h1->next;
	}

	// Inserting FAS List into ALL List
	while (h2 != NULL) {

		current = all->head;

		while (current != NULL) {

			if (h2->data == current->data) {

				flag = true;
			}

			current = current->next;
		}

		if (flag == false) {

			all->InsertAtEnd(h2->data);
		}

		flag = false;

		h2 = h2->next;
	}

	// Inserting FDS List into ALL List
	while (h3 != NULL) {

		current = all->head;

		while (current != NULL) {

			if (h3->data == current->data) {

				flag = true;
			}

			current = current->next;
		}

		if (flag == false) {

			all->InsertAtEnd(h3->data);
		}

		flag = false;

		h3 = h3->next;
	}

	// Printing out the collected ALL List
	current = all->head;

	int counter = 0;

	for (int i = 1; current != NULL; i++) {

		
		counter++;

		current = current->next;
	}

	// Saving the List into a string*
	result = new string[counter + 1];
	int i = 0;
	current = all->head;

	for (i = 0; current != NULL; i++) {

		result[i] = current->data;

		current = current->next;
	}

	result[i][0] = '\0';

	return result;
}


string* list_common_student_society(student_Node* head1, student_Node* head2, student_Node* head3)
{

	string* result;

	//enter your code here

	student_Node* addh1 = head1;
	student_Node* addh2 = head2;
	student_Node* addh3 = head3;

	result = new string[10];
	int counter = 0;

	while (addh3 != NULL) {

		addh2 = head2;

		while (addh2 != NULL) {

			addh1 = head1;

			while (addh1 != NULL) {

				if (addh1->data == addh2->data && addh1->data == addh3->data) {

					result[counter] = addh1->data;
					counter++;
				}

				addh1 = addh1->next;
			}

			addh2 = addh2->next;
		}

		addh3 = addh3->next;
	}

	result[counter][0] = '\0';

	return result;
}

void mainOfQuestion1() {

	TOPMenu1();

	student_Node* FGC_List;
	student_Node* FAS_List;
	student_Node* FDS_List;
	string* result;
	string* result2;

	//fill all llist

	// Filling FGC List
	LinkedList* fgc = new LinkedList;

	fgc->Fill_fgc();

	// Filling FAS List
	LinkedList* fas = new LinkedList;

	fas->Fill_fas();

	// Filling FDS List

	LinkedList* fds = new LinkedList;

	fds->Fill_fds();

	//call both funcations

	result = list_of_all_students(fgc->head, fas->head, fds->head);

	result2 = list_common_student_society(fgc->head, fas->head, fds->head);

	//print results;

	FGC_List = fgc->head;
	FAS_List = fas->head;
	FDS_List = fds->head;

	int counter = 0;

	cout << endl << "List of FGC Students" << endl;
	for (int i = 1; FGC_List != NULL; i++) {

		cout << i << "  " << FGC_List->data << endl;

		FGC_List = FGC_List->next;

		counter++;
	}

	cout << endl << "List of FAS Students" << endl;
	for (int i = 1; FAS_List != NULL; i++) {

		cout << i << "  " << FAS_List->data << endl;

		FAS_List = FAS_List->next;

		counter++;
	}

	cout << endl << "List of FDS Students" << endl;
	for (int i = 1; FDS_List != NULL; i++) {

		cout << i << "  " << FDS_List->data << endl;

		FDS_List = FDS_List->next;

		counter++;
	}

	cout << endl << "List of All Students" << endl;
	for (int i = 1; result[i - 1][0] != '\0'; i++) {

		cout << i << "  " << result[i - 1] << endl;
	}

	counter = sizeof(result2) / sizeof(result2[0]);

	cout << endl << "List of Common Students" << endl;
	for (int i = 1; result[i - 1][0] != '\0'; i++) {

		cout << i << "  " << result2[i - 1] << endl;
	}
}