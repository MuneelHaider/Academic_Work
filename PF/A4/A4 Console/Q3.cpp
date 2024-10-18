/*	Muneel Haider	*
*	21i-0640		*
*	Assignment 4	*
*	Question 3		*/

#include<iostream>
#include<String>
#include"Q3.h"

using namespace std;

int main() {

	int Assets; 
	int Type;  
	int Balance; 
	int Year, Cost;
	int Current_Worth;
	float LandArea;
	string Location;
	string Icon;

	RealEstate RealEstate_obj;

	DividendStock DividendStock_obj;
	
	Currency Currency_obj;
	
	Simple_Stock Simple_Stock_obj;

	int Looper;
	int Looper_2;

	displayCustom();

	do{

		cout << "Choose the type of assets:" << endl;

		cout << "Press 1 to select Stocks." << endl;
		cout << "Press 2 to select Real Estate." << endl;
		cout << "Press 3 to select Currency." << endl << endl;
		
		cin >> Assets;

		switch (Assets) {
			 
		case 1: {

			do {
					
				cout << "Stock Type:" << endl;
				cout << "Press 1: Simple Stocks." << endl;
				cout << "Press 2: Dividend Stocks." << endl;
	
				cin >> Type;

				switch (Type) {

				case 1: {

					cout << "Simple Stocks:" << endl;

					cout << "Press 1 to select the icon of stock." << endl;
					cout << "Press 2 to add more stock." << endl;
					cout << "Press 3 to calculate total stock." << endl;
					cout << "Press 4 to calculate total market price of stock." << endl;
					cout << "Press 5 to reduce the stocks." << endl;
					cout << "Press 6 to check the profit of stocks." << endl;

					cin >> Type;

					switch (Type) {

					case 1: {

						cout << "Enter the Icon:	";
						cin >> Icon;

						Simple_Stock_obj.set_Icon(Icon);

						cout << "Your new updated icon is:	" << Simple_Stock_obj.get_Icon() << endl;

						break;
					}

					case 2: {

						cout << "Enter the number of stocks you want to increase:	";

						cin >> Balance;

						Simple_Stock_obj.set_total_stock(Balance);

						cout << "Your total amount of stocks:	" << Simple_Stock_obj.get_total_stock() << endl;

						break;
					}

					case 3: {

						cout << "Enter cost of each stock:	";

						cin >> Balance;

						Simple_Stock_obj.set_TotalCost(Balance);

						cout << "The total cost of stocks is:	" << Simple_Stock_obj.get_TotalCost() << endl;

						break;
					}

					case 4: {

						cout << "Enter current market price of each stock:	";

						cin >> Balance;

						Simple_Stock_obj.set_T_Current_StockPrice(Balance);

						cout << "The total cost of stocks is:	" << Simple_Stock_obj.get_T_Current_StockPrice() << endl;

						break;
					}

					case 5: {

						cout << "Enter the amount of stocks you want to reduce:	";

						cin >> Balance;

						Simple_Stock_obj.sub_stock(Balance);

						cout << "The total amount of stocks left is:	" << Simple_Stock_obj.get_total_stock();

						break;
					}

					case 6: {

						cout << "Enter the price of each stock:	";

						cin >> Balance;

						Simple_Stock_obj.set_T_Current_StockPrice(Balance);

						cout << "Enter cost of each stock:	";

						cin >> Balance;

						Simple_Stock_obj.set_TotalCost(Balance);

						cout << "The total profit:	" << Simple_Stock_obj.get_compute_profit() << endl;

						break;
					}

						  break;
					}

				case 2: {

					cout << "NOTICE:	Profit sharing amount is 5% of the Total Assets." << endl;
					cout << endl << "Dividend Stocks :" << endl;

					cout << "Press 1 to select the icon of stock." << endl;
					cout << "Press 2 to add more stock." << endl;
					cout << "Press 3 to calculate total stock." << endl;
					cout << "Press 4 to calculate total market price of stock." << endl;
					cout << "Press 5 to reduce the stocks." << endl;
					cout << "Press 6 to check the profit of stocks." << endl;

					cin >> Type;

					switch (Type) {

					case 1: {

						cout << "Enter the Icon:	";
						cin >> Icon;

						DividendStock_obj.set_Icon(Icon);

						cout << "Your new updated icon is:	" << DividendStock_obj.get_Icon() << endl;

						break;
					}

					case 2: {

						cout << "Enter the number of stocks you want to increase:	";

						cin >> Balance;

						DividendStock_obj.set_total_stock(Balance);

						cout << "Your total amount of stocks:	" << DividendStock_obj.get_total_stock() << endl;

						break;
					}

					case 3: {

						cout << "Enter cost of each stock:	";

						cin >> Balance;

						DividendStock_obj.set_TotalCost(Balance);

						cout << "The total cost of stocks is:	" << DividendStock_obj.get_TotalCost() << endl;

						break;
					}

					case 4: {

						cout << "Enter current market price of each stock:	";

						cin >> Balance;

						DividendStock_obj.set_T_Current_StockPrice(Balance);

						cout << "The total cost of stocks is:	" << DividendStock_obj.get_T_Current_StockPrice() << endl;

						break;
					}

					case 5: {

						cout << "Enter the amount of stocks you want to reduce:	";

						cin >> Balance;

						DividendStock_obj.sub_stock(Balance);

						cout << "The total amount of stocks left is:	" << DividendStock_obj.get_total_stock();

						break;
					}

					case 6: {

						cout << "Enter the price of each stock:	";

						cin >> Balance;

						DividendStock_obj.set_T_Current_StockPrice(Balance);

						cout << "Enter cost of each stock:	";

						cin >> Balance;

						DividendStock_obj.set_TotalCost(Balance);

						cout << "The total profit:	" << DividendStock_obj.get_compute_profit() << endl;

						break;
					}

						  break;
					}

					break;
				}

				cout << endl << endl;
					  cout << "Do you want to run the program again?" << endl;
					  cout << "If yes, please press 1. Or else press any key to exit." << endl;
					  
					  cin >> Looper;
				}
			}
		
		}while (Looper == 1);

		break;
	}


		case 2: {       

			do {

				cout << "Press 1: To set location" << endl;
				cout << "Press 2: To set land area" << endl;
				cout << "Press 3: To set year of purchase" << endl;
				cout << "Press 4: To set cost of estate" << endl;
				cout << "Press 5: To set current market value" << endl;
				cout << "Press 6: To set new land area purchase date" << endl;
				cout << "Press 7: To add land area" << endl;
				cout << "Press 8: To set new land area of cost of estate" << endl;
				cout << "Press 9: To reduce the land area" << endl;
				cout << "Press 10: To get total current market value of assets" << endl;
				cout << "Press 11: To get total profit of assets" << endl;
				
				cin >> Type;
				
				switch (Type) {
				
					case 1: {

						cout << "Enter the Location:	";

						cin >> Location;

						RealEstate_obj.set_Location(Location);

						cout << "Updated Location is:	" << RealEstate_obj.get_Location() << endl;

						break;
					}

					case 2: {
						cout << "Enter the land area:	";
					
						cin >> LandArea;
						
						RealEstate_obj.set_LandArea(LandArea);
						
						cout << "Updated land area:	" << RealEstate_obj.get_LandArea() << endl;
						
						break;
					}
					case 3: {

						cout << "Enter The year of purchase:	";
						
						cin >> Year;
						
						RealEstate_obj.set_Year_of_purchase(Year);
						
						cout << "Updated Year:	" << RealEstate_obj.get_Year_of_purchase() << endl;
						
						break;
					}
					case 4: {

						cout << "Enter the cost of purchase of per meter:	" << endl;
						
						cin >> Cost;
						
						RealEstate_obj.set_Cost(Cost);
						
						cout << "Updated cost:	" << RealEstate_obj.get_Cost() << endl;
						
						break;
					}
					case 5: {

						cout << "Enter the current market value of 1 meter:	";
						
						cin >> Current_Worth;
						
						RealEstate_obj.set_current_market_value(Current_Worth);
						
						cout << "Total assets value:	" << RealEstate_obj.get_current_market_value();
						
						break;
					}
					case 6: {

						cout << "Enter the purchase year of new assets:	";
						
						cin >> Year;
						
						RealEstate_obj.set_Year_of_purchase(Year);
						
						cout << "Updated year of purchase:	" << RealEstate_obj.get_Year_of_purchase() << endl;
						
						break;
					}
					case 7: {

						cout << "Enter to add new land area:	";
						
						cin >> LandArea;
						
						RealEstate_obj.add_asset(LandArea);
						
						cout << "Update land area:	" << RealEstate_obj.get_LandArea() << endl;
						
						break;
					}
					case 8: {

						cout << "Add the new cost of land area:	";
						
						cin >> Cost;
						
						RealEstate_obj.set_Cost(Cost);
						
						cout << "Updated cost:	" << RealEstate_obj.get_Cost() << endl;
						
						break;
					}
					case 9: {

						cout << "Enter the amount of reduced land area:	";
						
						cin >> LandArea;
						
						RealEstate_obj.sub_asset(LandArea);
						
						cout << "Updated land area:	" << RealEstate_obj.get_LandArea() << endl;
						
						break;
					}
					case 10: {

						cout << "Enter current value of land area per meter:	";
						
						cin >> Current_Worth;

						cout << "Total market value of Assets:	"<<RealEstate_obj.compute_Total_Current_Worth(Cost);
						
						cout << endl;
						
						break;
					}
					case 11: {

						cout << "Enter current value of per one meter LandArea:	";
						
						cin >> Current_Worth;
						
						cout << "Enter the cost of one meter:	";
						
						cin >> Cost;
						
						cout << "Total profit of assets:	"<<RealEstate_obj.compute_profit(Current_Worth, Cost);
						
						cout << endl;
						
						break;
					}
				}

				cout << endl << endl;
				
				cout << "Would you like to run the program again? If yes please press 1, else press any number to exit." << endl;
				
				cin >> Looper;
			
	} while (Looper == 1);
	
	break;

}

		case 3: {

			do {

				cout << " Press 1: Check amount invested." << endl;
				cout << " Press 2: Add amount" << endl;
				cout << " Press 3: Subtact the amount invested." << endl;
				
				cin >> Type;
				
				switch (Type) {
				
				case 1: {

					cout << "Your current balance is:	" << Currency_obj.get_currency() << endl;
					break;
				}

				case 2: {

					cout << "Enter the currency you want to add:	";
					
					cin >> Balance;
					
					cout << "Previous Currency:	" << Currency_obj.get_currency() << endl;
					
					Currency_obj.add_currency(Balance);
					
					cout << "Updated Cuurency:	" << Currency_obj.get_currency() << endl;
					
					break;
				}

				case 3: {

					cout << "Enter the currency you want to substract:	";
					
					cin >> Balance;
					
					cout << "Previous Currency:	" << Currency_obj.get_currency() << endl;
					
					Currency_obj.sub_currency(Balance);
					
					cout << "Updated Cuurency:	" << Currency_obj.get_currency() << endl;
					
					break;
				}
				}

				cout << endl << endl;
				
				cout << "Would you like to run the program again? If yes please press 1, or else press any number." << endl;

				cin >> Looper;

			} while (Looper == 1);

			break;
		}

		}
	
		cout << endl << endl;
		
		cout << "Would you like to run the program again? If yes please press 1, or else press any number." << endl;

		cin >> Looper_2;

	}while (Looper_2 == 1);

	return 0;
}