//
///*	Muneel Haider	*
//*	21i-0640		*
//*	Assignment 4	*
//*	Question 2		*/
//
//#include<iostream>
//#include<string>
//#include"Q2.h"
//
//using namespace std;
//
//int main() {
//
//	int Money_Withdraw;
//	int Deposit_Amount;
//	int Case_Identifier;
//	int counter_1;
//	int Looper_2_Identifier;
//	int static CustomerNo_ = 0;
//	char Looper;
//
//	string AccType;
//	string First_Name;
//	string Middle_Name;
//	string Last_Name;
//	string CNIC;
//	string Address;
//	string TelephoneNum;
//	string Date_of_birth;
//	string AccNum;
//	string CreditCard_number;
//
//	displayCustom();
//
//	ExistingCustomer_Operations obj[10];
//
//	cout << " Welcome! " << endl;
//	cout << " Screen for Bank Employee Only! " << endl << endl;
//
//	do {
//
//		counter_1 = 0;
//		AccNum = "2022-";
//
//		cout << "Press  1 to create a new account." << endl;
//		cout << "Press  2 to access existing customers." << endl;
//		cout << "Press  3 to generate the list of all customers." << endl << endl;
//
//		cin >> Case_Identifier;
//
//		switch (Case_Identifier) {
//
//			case 1: {
//
//				cout << "Account Types: " << endl << endl;
//				cout << "Press 1 to check account." << endl;
//				cout << "Press 2 to for savings account." << endl;
//				cout << "Enter: \t";
//				cin >> AccType;
//
//				cout << endl << "Enter First Name:	 	 ";
//				cin >> First_Name;
//
//				cout << endl << "Enter Middle Name:		 ";
//				cin >> Middle_Name;
//
//				cout << endl << "Enter Last Name:		 ";
//				cin >> Last_Name;
//
//				cout << endl << "Enter Address:			 ";
//				cin >> Address;
//
//				cout << endl << "Enter CNIC Number ( CNIC Number input should be greater than 6 digits ):		 ";
//				cin >> CNIC;
//
//				cout << endl << "Enter Telephone Number: ";
//				cin >> TelephoneNum;
//
//				cout << endl << "Enter Date of Birth:	 ";
//				cin >> Date_of_birth;
//
//				cout << endl << endl;
//
//				while (CNIC[counter_1] != '\0') {
//
//					counter_1++;
//				}
//
//				int j = 0;
//
//				while(j < 6) {
//
//					AccNum += CNIC[counter_1 - 6 + j];
//					j++;
//				}
//
//				CreditCard_number += First_Name[0];
//				CreditCard_number += Middle_Name[0];
//				CreditCard_number += Last_Name[0];
//
//				CreditCard_number += AccNum;
//			
//				cout << "Account Number:	 " << AccNum << endl;
//			
//				cout << endl << "Credit Card No:	 " << CreditCard_number << endl << endl;
//
//				obj[CustomerNo_] = ExistingCustomer_Operations(AccType, First_Name, Middle_Name, Last_Name, CNIC, Address, TelephoneNum, Date_of_birth , AccNum,CreditCard_number);
//			
//				CustomerNo_++;
//
//				break;
//			}
//
//			case 2: {
//
//				cout << "Press  1  to generate mini statement of a bank customer." << endl;
//				cout << "Press  2  to withdraw money from a customer account." << endl;
//				cout << "Press  3  to deposit money." << endl;
//				cout << "Press  4  for Balance Inquiry." << endl;
//				cout << "Press  5  for transaction history." << endl;
//
//				cin >> Looper_2_Identifier;
//			
//				switch (Looper_2_Identifier) {
//
//					case 1: {
//
//						cout << endl << "Generating mini statement of a customer." << endl;
//
//						cout << endl << "Plase enter your account number:	 ";
//						cin >> AccNum;
//
//						cout << endl << "Please enter your CNIC:	 ";
//						cin >> CNIC;
//
//						for (int i = 0; i < CustomerNo_; i++) {
//
//							if (CNIC == obj[i].get_CNIC() && AccNum == obj[i].get_AccNum()) {
//
//								obj[i].GenerateSlip_Customer();
//								break;
//							}
//						}
//
//						break;
//					}
//
//					case 2: {
//
//							cout << endl << "Enter credit card number:	 ";
//							cin >> CreditCard_number;
//
//							cout << endl << "Enter money you want to withdraw:	 ";
//							cin >> Money_Withdraw;
//
//							for (int i = 0; i < CustomerNo_; i++) {
//
//								if (obj[i].get_CreditCard_number() == CreditCard_number) {
//
//									obj[i].Money_Withdrawed(Money_Withdraw);
//									break;
//								}
//							}
//
//						break;
//					}
//
//					case 3: {
//
//						cout << endl << "Enter Account number:	 ";
//						cin >> AccNum;
//
//						cout << endl << "Enter CNIC number:		 ";
//						cin >> CNIC;
//
//						cout << endl << "Enter amount Deposit:	 ";
//						cin >> Deposit_Amount;
//
//						for (int i = 0; i < CustomerNo_; i++) {
//
//							if (obj[i].get_CreditCard_number() == CreditCard_number) {
//
//								obj[i].deposit_money(Deposit_Amount);
//								break;
//							}
//						}
//
//						break;
//					}
//
//					case 4: {
//
//						cout << "Enter Account number:	" << endl;
//						cin >> AccNum;
//
//						cout << "Enter CNIC number:		" << endl;
//						cin >> CNIC;
//
//						for (int i = 0; i < CustomerNo_; i++) {
//
//							if (AccNum == obj[i].get_AccNum() && CNIC == obj[i].get_CNIC()) {
//
//								cout << "Your Balance is:	" << obj[i].get_Balance() << endl;
//								break;
//							}
//						}
//
//						break;
//					}
//
//					case 5: {
//
//						cout << "Enter Account number:	 ";
//						cin >> AccNum;
//
//						cout << "Enter CNIC number:		 ";
//						cin >> CNIC;
//
//						for (int i = 0; i < CustomerNo_; i++) {
//
//							if (AccNum == obj[i].get_AccNum() && CNIC == obj[i].get_CNIC()) {
//
//								obj[i].Total_Transactions();
//								break;
//							}
//						}
//
//						break;
//					}
//
//				}
//
//				break;
//			}
//
//
//			case 3: {
//
//				Generate_List List;
//			
//				for (int i = 0; i < CustomerNo_; i++) {
//
//					List.display(obj[i]);
//				}
//
//				break;
//			}
//		}
//
//		cout << "Would you want to do another operation?" << endl;
//		cout << "Press Y to continue, else press any key." << endl;
//		
//		cin >> Looper;
//	
//	}while (Looper=='Y' || Looper == 'y');
//	
//	return 0;
//}