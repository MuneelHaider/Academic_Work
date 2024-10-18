
/*	Muneel Haider		*
*	21i-0640			*
*	Assignment 4		*
*	Question 2.h File	*/

#pragma once
#include<iostream>
#include<string>

using namespace std;

void displayCustom() {

	cout << "	Muneel Haider	" << endl;
	cout << "	21i-0640		" << endl;
	cout << "	Assignment 4	" << endl;
	cout << "	Question 3		" << endl << endl << endl;

}

class ExistingCustomer_Operations {

	int Balance;
	string AccType;
	string First_name;
	string Middle_Name;
	string Last_Name;
	string CNIC;
	string Address;
	string Telephone_Number;
	string Date_of_Birth;
	string AccNum;
	string CreditCard_Number;

	int Deposit_List[5];
	int Withdrawn_Money_Record[5];

public:

	ExistingCustomer_Operations(string AccType = "", string First_name = "", string Middle_Name = "", string Last_Name="", string CNIC = "", string Address="", string Telephone_Number="", string Date_of_Birth="" , string AccNum="", string CreditCard_Number="") {

		Balance = 0;
		
		this->AccType= AccType; 
		
		this->First_name= First_name; 
		
		this->Middle_Name= Middle_Name; 
		
		this->Last_Name= Last_Name; 
		
		this->CNIC= CNIC;
		
		this->Address= Address; 
		
		this->Telephone_Number= Telephone_Number;
		
		this->Date_of_Birth= Date_of_Birth;
		
		this->AccNum = AccNum;
		
		this->CreditCard_Number = CreditCard_Number;

		Deposit_List[0] = '\0';

		Withdrawn_Money_Record[0] = '\0';
	}

	int get_Balance() {

		return Balance;
	}

	string get_AccNum() {
		
		return AccNum;
	}

	string get_AccType() {

		return AccType;
	}

	string get_CNIC() {
		
		return CNIC;
	}
	string get_CreditCard_number() {
		
		return CreditCard_Number;
	}
	
	void Money_Withdrawed (int Withdrawing_Money) {
		
		cout << endl << "Money Receipt" << endl;

		cout << "Your current Balance is:	" << Balance << endl;
		
		if (Withdrawing_Money < Balance) {
		
			Balance -= Withdrawing_Money;

			cout << "Withdrawn Money:		" << Withdrawing_Money << endl;

			cout << "Remanining Balance:	" << Balance << endl;

			for (int i = 0; Withdrawn_Money_Record[i] == '\0'; i++) {
			
				Withdrawn_Money_Record[i] = Withdrawing_Money;
				Withdrawn_Money_Record[i + 1] = '\0';
				
				break;
			}
		}

		else {

			cout << "Your balance is insufficient. Please try again later." << endl << endl;	
		}
	}

	void deposit_money(int Deposit_Amount) {

		cout << endl << "Money Receipt" << endl;

		cout << "Your balance is:	" << Balance << endl;

	    Balance += Deposit_Amount;
	    
		cout << " Deposited Amount:		" << Deposit_Amount << endl;
		
		cout << " Total Balance:		" << Balance << endl;

		for (int i = 0; i < Deposit_List[i] == '\0'; i++) {
		
			Deposit_List[i] = Deposit_Amount;
			
			Deposit_List[i + 1] = '\0';

			break;
		}
    }

	void Balance_inquiry() {

		cout << "Your total balance is:	" << Balance << endl << endl;
	}

	void Total_Transactions() {

		cout << "History of deposits:	" << endl;

		int i = 0;

		for (i = 0; i < Deposit_List[i] != '\0'; i++) {

			cout << "Amount Deposit:	" << Deposit_List[i] << endl;
		}

		cout << endl << endl << "Withdrawn History:	" << endl;
		
		while (Withdrawn_Money_Record[i] != '\0') {
			cout << "Amount withdrawn:	" << Withdrawn_Money_Record[i] << endl;
			i++;
		}

	}

	void GenerateSlip_Customer() {
    
		Total_Transactions();
	}
};

int static StaticCounter = 0;

class NewAccount  {

	string AccType;
	string Acc_Number;
	string First_name;
	string Middle_Name;
	string Last_Name;
	string CNIC;
	string Address;
	string Telephone_Number;
	string Date_of_Birth;
	string AccNum;
	string CreditCard_Number;

public:
	NewAccount(string AccType, string First_name, string  Middle_Name, string Last_Name, string CNIC, string Address, string Telephone_Number, string Date_of_Birth) {

		this->AccType; 
		
		this->First_name; 
		
		this->Middle_Name; 
		
		this->Last_Name; 
		
		this->CNIC;
		
		this->Address; 
		
		this->Telephone_Number; 
		
		this->Date_of_Birth;

		int CNIC_Length = 0;

		while (CNIC[CNIC_Length] != '\0') {

			CNIC_Length++;
		}

		CNIC_Length--;

		Acc_Number = "2022-";

		for (int i = 0; i < 6; i++) {

			Acc_Number += CNIC[CNIC_Length - 6 + i];
		}

		CreditCard_Number += First_name[0];
		CreditCard_Number += Middle_Name[0];
		CreditCard_Number += Last_Name[0];

		CreditCard_Number += Acc_Number;
		
		cout << " Account Number:	" << Acc_Number << endl;
		cout << " Credit Card No:	" << CreditCard_Number << endl;
		
		StaticCounter++;	
	}
	
	string get_CreditCard_number() {
		return CreditCard_Number;
	}

	string get_Acc_Number() {
		return Acc_Number;
    }
};

class Generate_List {

public:

	void display(ExistingCustomer_Operations obj) {

		cout << "Account Numer:			" << obj.get_AccNum() << endl;
		cout << "Account Type:			" << obj.get_AccType() << endl;
		cout << "Your Balance:			" << obj.get_Balance() << endl << endl;
	}
};