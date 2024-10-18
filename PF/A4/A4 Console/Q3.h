
/*	Muneel Haider		*
*	21i-0640			*
*	Assignment 4		*
*	Question 3.h File	*/

#pragma once
#include<iostream>
#include<string>
using namespace std;

void displayCustom() {

	cout << "	Muneel Haider	" << endl;
	cout << "	21i-0640		" << endl;
	cout << "	Assignment 4	" << endl;
	cout << "	Question 3		" << endl << endl << endl << endl;

}
                                                                                // Stock
class Stock {

    string Icon;
	int TotalShares;
	int TotalCost;
	int Current_StockPrice;
	int T_Current_StockPrice;
	int TotalProfit;

public:

	Stock (string Icon = "", int TotalShares = 0, int TotalCost0 = 0, int Current_StockPrice = 0) {
		this->Icon = Icon; this->TotalShares = TotalShares; this->TotalCost = TotalCost;
		this->Current_StockPrice = Current_StockPrice;
	}
	void set_Icon(string symb) {
		Icon = symb;
	}
	void set_total_stock(int share) {
		TotalShares += share;
	}
	int get_total_stock() {
		return TotalShares;
	}
	void set_TotalCost(int Cost) {
		TotalCost = Cost* get_total_stock();
	}
	void set_Current_StockPrice(int stck) {
		Current_StockPrice = stck;
	}

	/*-------------*/

	string get_Icon() {
	return 	Icon;
	}
	
	int  get_TotalCost() {
		return TotalCost;
	}
	int get_Current_StockPrice() {
		return Current_StockPrice;
	}
	void set_T_Current_StockPrice(int Balance) {
		T_Current_StockPrice = Balance * get_total_stock();
	}

	int get_T_Current_StockPrice() {
		return T_Current_StockPrice;
	}

    
	void sub_stock( int sub) {
		if (TotalShares >= sub) {
			TotalShares -= sub;
		}
		else
			cout << " Number of stocks are not enough" << endl;
	}

	/*-------*/

	void  set_compute_profit( int Balance) {
         
	}
	int get_compute_profit() {
		return get_T_Current_StockPrice() - get_TotalCost();
	}
	
};

class Simple_Stock:public Stock {                                                     // Simply stock
public:

	Simple_Stock(string Icon="", int TotalShares=0, int TotalCost=0, int Current_StockPrice=0):
		Stock(Icon , TotalShares ,  TotalCost,  Current_StockPrice){}
};
  



// Dividend Stock
class DividendStock:public Stock {

	int no_of_share;
	int profit_sharing_payments;
public:

	DividendStock(string Icon = "", int TotalShares = 0, int TotalCost = 0, int Current_StockPrice = 0,
		int no_of_share = 0, int profit_sharing_payments = 0) :
		Stock(Icon, TotalShares, TotalCost, Current_StockPrice) {

		this->no_of_share = no_of_share;
		this->profit_sharing_payments = profit_sharing_payments;
	}

	int get_profit_of_DividendStock() {
		cout << " Profit sharing payment : " << ((get_total_stock() * 5) % 100) << endl;
		cout << " Total Profit : " << get_compute_profit() + ((get_total_stock() * 5) % 100) << endl;
		return get_compute_profit() + ((get_total_stock() * 5) % 100);
	}
};



class RealEstate {                                                                   // Real Stock

	string Location;
	float LandArea;          // square-meter
	int Year_of_purchase, Cost, current_market_value;
public:

	RealEstate(string Location="", float LandArea=0, int Year_of_purchase=0, int Cost=0, int current_market_value=0) {
		this->Location = Location; this->LandArea = LandArea; this->Year_of_purchase = Year_of_purchase;
		this->Cost = Cost; this->current_market_value = current_market_value;
	}  /*-----*/

	void set_Location(string input) {
		Location += " ";
		Location +=input;
	}
	void set_LandArea(float LandArea1) {
		LandArea += LandArea1;
	}
	void set_Year_of_purchase(int Year1) {
		Year_of_purchase = Year1; 
	}
	void set_Cost(int Cost1_) {
		Cost += Cost1_;
	}
	void set_current_market_value(int Current_Worth) {
		current_market_value = Current_Worth;
	}

	string get_Location() { 
		return Location;
	}
	float get_LandArea() {
		return LandArea;
	}
	int get_Year_of_purchase() {
		return Year_of_purchase;
	}
	int get_Cost() { 
		return Cost;
	}
	int get_current_market_value() {
		return current_market_value ;
	}

	void add_asset( int LandArea1) {
		LandArea += LandArea1;
	}
	void sub_asset(int LandArea1) {
		LandArea -= LandArea1;
	}
	
	int compute_Total_Current_Worth(int value) {
		return value * get_LandArea();
	}

	int compute_profit( int current, int Cost) {
	
		return (compute_Total_Current_Worth(current) - ( get_LandArea()*Cost));
	}
	

};



class Currency {                                                                     // Currency;

	int amount_investor;
public:

	Currency() {
		amount_investor = 0;
	}
	void add_currency(int amount) {

		amount_investor += amount;

	}
	void sub_currency(int amount) {
		if (amount_investor >= amount) {
			amount_investor -= amount;
		}
		else
			cout << " Your Currency is not enugh as you substract" << endl;
	}

	int get_currency() {
		return amount_investor;
	}
	/*-------*/

	
};
