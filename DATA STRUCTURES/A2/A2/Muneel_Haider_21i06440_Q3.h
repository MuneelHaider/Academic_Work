#pragma once
#include<iostream>
using namespace std;

// Muneel_Haider_21i0640

void TOPMenu3() {

	system("CLS");
	system("color 3");

	cout << "******************************************" << endl;
	cout << "*					 *" << endl;
	cout << "*	Muneel Haider 21i-0640		 *" << endl;
	cout << "*	Assignment 3 Data Structures	 *" << endl;
	cout << "*					 *" << endl;
	cout << "******************************************" << endl;
	cout << endl << "QUESTION 3";
	cout << endl << endl << endl << endl << endl;
}

class lift_floors {
public:

	int  floor;
	char floor_status; //A for active N for not active
	lift_floors* next;
	lift_floors* prev;

	lift_floors(int data) {
		this->floor = data;
		this->next = NULL;
		this->prev = NULL;
		this->floor_status = 'A';
	}
};

class DBList {

public:

	lift_floors* head;
	lift_floors* tail;

	DBList() {

		head = NULL;
		tail = NULL;
	}

	void insertAtStart(lift_floors* node) {

		node = new lift_floors(-1);
		lift_floors* temp = new lift_floors(-1);

		node->floor = temp->floor;

		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL) {

			head = temp;
			tail = temp;
		}
		else {

			temp->next = head;
			head = temp;
		}

		temp = NULL;
		delete temp;

		cout << "inserted 1st node" << endl;

		return;
	}

	void InsertAtEndNode(int d, lift_floors*& head, lift_floors*& tail) {

		lift_floors* temp = new lift_floors(d);

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

		cout << "Inserted at end node." << endl;

		return;
	}
};

void InsertAtEndNode(int d, lift_floors*& head, lift_floors*& tail) {

	lift_floors* temp = new lift_floors(d);

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

	cout << "Inserted at end node." << endl;

	return;
}

int liftup(lift_floors*& current, lift_floors* head, lift_floors* tail, int requested_floor)
{

	if (current->next == NULL) {

		return current->floor;
	}

	current = current->next;

	if (current->floor == requested_floor && current != NULL) {

		return current->floor;
	}

	return liftup(current, head, tail, requested_floor);
}
int liftdown(lift_floors*& current, lift_floors* head, lift_floors* tail, int requested_floor)
{
	if (current->prev == NULL) {

		return current->floor;
	}

	current = current->prev;

	if (current->floor == requested_floor && current != NULL) {

		return current->floor;
	}

	return liftdown(current, head, tail, requested_floor);
}
char halt_lift(char status)
{
	//halts the lift, no up and down operation can be performed. Stored H for halting
	
	status = 'H';

	return 'H';
}
char un_halt_lift(char status)
{
	//Unhatls the lift. Store W which represents that the lift is working
	
	status = 'W';
	
	return 'W';
}
void add_floor(lift_floors* new_floor, lift_floors*& head, lift_floors*& tail)
{
	int temp = 0;

	cout << endl << "We current have " << tail->floor << " floor(s). Do you want to add another?" << endl << "Press 1 for yes" << endl << "Press 0 for no" << endl;
	cin >> temp;

	if (temp == 1) {

		new_floor = new lift_floors(tail->floor + 1);

		InsertAtEndNode(new_floor->floor, head, tail);
	}
	else {

		return;
	}
}
void skip_floor(lift_floors*& head, lift_floors*& tail, int floorNo)
{
	lift_floors* current = head;

	while (current->floor != floorNo && current != NULL) {
	
		current = current->next;
	}

	current->floor_status = 'N';
}
void make_floor_operational(lift_floors*& head, lift_floors*& tail, int floorNo)
{
	lift_floors* current = head;

	while (current->floor != floorNo && current != NULL) {
	
		current = current->next;
	}

	current->floor_status = 'A';

	//add logic to make lift operational on a certain floor
}

int lift_operating_system(int requested_floor, lift_floors*& current, lift_floors* head, lift_floors* tail, char lift_status)
{
	//all lift related logic will be written in this bloack along with validation. In this funcation, decide
	//if the lift goes up or down

	lift_floors* temp = new lift_floors(0);
	temp = head;

	while (temp != NULL && temp->floor != requested_floor) {

		temp = temp->next;
	}
	if (temp->floor_status == 'N') {

		cout << endl << "This floor is currently inactive." << endl;
	
		return current->floor;
	}

	if (lift_status == 'H') {

		cout << endl << "The lift is currently halted. It cannot be used." << endl;
		
		return current->floor;
	}

	if (current->floor_status == 'A') {

		if (requested_floor > current->floor) {

			liftup(current, head, tail, requested_floor);

			cout << endl << "You are now at " << current->floor << " floor." << endl;
		}
		else if (requested_floor < current->floor) {

			liftdown(current, head, tail, requested_floor);
			cout << endl << "You are now at " << current->floor << " floor." << endl;
		}
		else if (requested_floor == current->floor) {

			cout << endl << "You are already at that floor." << endl;
		}
	}
	else {

		cout << endl << "That floor is currently inactive" << endl << endl;
	}

	return 0;
}

void mainOfQuestion3()
{
	TOPMenu3();

	lift_floors* head;
	lift_floors* tail;
	lift_floors* current;
	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service = -1; //choice of user
	int requested_floor; //floor the lift goes on
	char status = 'W'; //W for working , H for halted
	lift_floors* temp = new lift_floors(0);

	DBList* all = new DBList;

	head = all->head;
	current = all->head;

	all->insertAtStart(current);
	current_floor++;

	current = all->head;
	tail = all->head;

	for (int i = current_floor; i < 5; i++) {

		add_floor(temp, head, tail);
	}

	all->tail = tail;
	all->head = current;
	current_floor = -1;

	//initialize everything and poplate the link list based on above data.
	//use add floor to add all the floors in the list

	while (requested_service != 0)
	{
		cout << "Please select a funcation of your choice";
		cout << endl << "1. Go to a specific floor";
		cout << endl << "2. Halt Lift";
		cout << endl << "3. Unhalt Lift";
		cout << endl << "4. Make a floor unoperational.";
		cout << endl << "5. Make a floor operational.";
		cout << endl << "6. Add Floor.";
		cout << endl << "0. Exit" << endl;
		//.. add other options

		cin >> requested_service;
		switch (requested_service)
		case 1:
		{
			cout << endl << "Enter Floor of choice ";
			cin >> requested_floor;
			
			lift_operating_system(requested_floor, current, all->head, all->tail, status);//add arguments 
			break;

		case 2:
			cout << endl << "The Lift has been Halted." << endl;
			status = halt_lift(status);
			break;

		case 3:
			cout << endl << "The life has been Unhalted. You may use it now." << endl;
			status = un_halt_lift(status);
			break;
			
		case 4:
			cout << endl << "Which floor do you want to make unoperational?" << endl;
			cin >> requested_floor;

			skip_floor(all->head, all->tail, requested_floor);
			break;
			
		case 5:
			cout << endl << "Which floor do you want to make operational?" << endl;
			cin >> requested_floor;

			make_floor_operational(all->head, all->tail, requested_floor);
			break;
		
		case 6:
			add_floor(temp, head, tail);
			break;
		}
	}
}