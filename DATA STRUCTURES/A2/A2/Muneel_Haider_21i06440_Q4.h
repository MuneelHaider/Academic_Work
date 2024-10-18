#pragma once
#include<iostream>
#include<fstream>
using namespace std;

// Muneel_Haider_21i0640

void TOPMenu4() {

	system("CLS");
	system("color 3");

	cout << "******************************************" << endl;
	cout << "*					 *" << endl;
	cout << "*	Muneel Haider 21i-0640		 *" << endl;
	cout << "*	Assignment 3 Data Structures	 *" << endl;
	cout << "*					 *" << endl;
	cout << "******************************************" << endl;
	cout << endl << "QUESTION 4";
	cout << endl << endl << endl << endl << endl;
}

class StringList {

public:

	char alphabet;
	StringList* next;
	
	StringList(char data) {
		this->alphabet = data;
		this->next = NULL;

	}
};



class ListQ4 {

public:

	StringList* head;
	
	ListQ4() {

		head = NULL;
	}
};

int find_Length(StringList* s, int counter = 0) //counter will start from zero initially
{

	while (s->next != NULL) {

		counter++;
		s = s->next;
	}

	return counter;
}

class String_Manipulation {

public:

	void insertAtStart(StringList*& node) {

		StringList* temp = new StringList(' ');
		node = new StringList(' ');

		temp->alphabet = node->alphabet;

		temp->next = NULL;

		if (node == NULL) {

			node = temp;
		}
		else {

			temp->next = node;
			node = temp;
		}

		temp = NULL;
		delete temp;

		return;
	}

	void InsertAtEnd(StringList*& node, char d) {

		StringList* temp = new StringList(' ');

		temp->alphabet = d;

		temp->next = NULL;

		StringList* current = node;

		if (node == NULL) {

			node = temp;
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

	void InsertAtLocation(StringList* head, int l, char d) {

		StringList* temp = new StringList(d);
		temp->next = NULL;

		StringList* current = head;
		StringList* lmao = head->next;

		for (int i = 0; i < l - 1; i++) {

			current = lmao;
			lmao = lmao->next;
		}

		current->next = temp;
		temp->next = lmao;

	}

	void createList(StringList*& head)
	{
		//read text from file and make the list here
		insertAtStart(head);

		fstream file;
		StringList* current = head;
		char letter;

		file.open("Q4- String Paragraph.txt");

		while (file.get(letter)) {
	
			InsertAtEnd(current, letter);
			cout << current->alphabet;
			current = current->next;
		}	
		
	}

	int Calculate_length(StringList* head, int length = 0)
	{

		StringList* current = head;
		//call a recursive funcaiton to find string length
		//add your code
		/*
		The function should get a string as input and return the length of the string.
		The length should be measured with the help of a recursive function.
		*/

		if (current->next != NULL) {

			length++;
			current = current->next;
		}
		else {

			return length;
		}

		return Calculate_length(head);
	}
	bool substring(StringList* head, string str)
	{
		bool status;
		
		int index = 0;
		//add your code
		/*
			"I am taking DS course"
			Str = "taking"
			The function will return 5 as substring exist and starts at 5th index of main string. In case the substring does not exist, you will return -1.

		*/

		StringList* current = head;
		StringList* temp = head;
		int counter = 0;

		while (current != NULL) {

			temp = current;

			if (current->alphabet == str[0]) {

				while (counter != str.length() || temp != NULL) {

					if (temp->alphabet != str[counter]) {

						counter = 0;
						break;
					}

					temp = temp->next;
					counter++;

					if (counter == str.length()) {

						return true;
					}
				}


			}

			index++;
			current = current->next;
		}

		return false;
	}

	int substring_position(StringList* head, string str)
	{
		int index = 0;
		//add your code
		/*
			"I am taking DS course"
			Str = "taking"
			The function will return 5 as substring exist and starts at 5th index of main string. In case the substring does not exist, you will return -1.

		*/

		StringList* current = head;
		StringList* temp = head;
		int counter = 0;

		while (current != NULL) {

			temp = current;

			if (current->alphabet == str[0]) {
			
				while (counter != str.length() || temp != NULL) {

					if (temp->alphabet != str[counter]) {

						counter = 0;
						break;
					}

					temp = temp->next;
					counter++;

					if (counter == str.length()) {

						return index;
					}
				}

				
			}
			
			index++;
			current = current->next;
		}

		return -1;
	}
	void replaceString(StringList*& head, string find, string replace)
	{
		StringList* current = head;
		int counter = 0;

		while (current != NULL) {

			if (current->alphabet == find[0]) {

				current->alphabet = replace[0];
			}

			current = current->next;
		}
	}
	//void appendText(StringList*& head, string appends, int index)
	//{
	//	StringList* current = head;
	//	StringList* temp = head;
	//	int counter = 0;
	//	int j = 0;

	//	while (counter < index) {

	//		current = current->next;
	//		counter++;
	//	}

	//	for (int i = counter; i < appends.length(); i++) {

	//		InsertAtLocation(head, i, appends[j]);
	//		j++;
	//	}
	//}
	void deleteText(StringList*& head, string delText)
	{

		StringList* current = head;

		int index = substring_position(head, delText);
		if (index == -1) {

			cout << "Unable to Locate" << endl;
			return;
		}

		for (int i = 0; i < index - 1; i++) {

			current = current->next;
		}

		StringList* temp = current;

		for (int i = 0; i < delText.length() ; i++) {

			temp = temp->next;
		}

		current->next = temp->next;
	}
};
void mainOfQuestion4()
{
	TOPMenu4();

	StringList* head = new StringList(' ');
	String_Manipulation obj;
	ListQ4* all = new ListQ4;
	head = all->head;
	int counter = 0;
	
	obj.createList(all->head);
	all->head = all->head->next;
	all->head = all->head->next;
	head = all->head;
	//add your code

	// Length
	cout << endl << endl << "Length of the code is:\t" << find_Length(head) << endl << endl;

	// Position of string
	string t;
	string l;
	cout << "Enter what to search? :\t";
	cin >> t;

	cout << "Position of string:\t" << obj.substring_position(head, t) << endl << endl;

	bool flag = obj.substring(head, t);

	if (flag) {

		cout << "The string is found." << endl << endl;
	}
	else {

		cout << "The string is not found." << endl << endl;
	}

	cout << "Which character to replace?" << endl;
	cin >> t;
	cout << endl << "To replace it to?" << endl;
	cin >> l;

	obj.replaceString(head, t, l);

	cout << endl << "What text do you want to delete?" << endl;
	cin >> t;
	obj.deleteText(head, t);

	StringList* current = head;
	while (current != NULL) {

		cout << current->alphabet;

		current = current->next;
	}

}