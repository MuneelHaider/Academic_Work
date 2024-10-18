#include "pch.h"
#include <iostream>
using namespace std;

/*		Muneel Haider
        21i-0640
        Assignment 3		*/

class Date {

    int year;
    int month;
    int day;
    bool leap;

public:
    
    Date();
    Date(int y, int m, int d);
    
    int getYear();
    void setYear(int y);

    int getMonth();
    void setMonth(int m);

    int getDay();
    void setDay(int d);

    void leaper();
    
    Date operator=(Date& d);
    
    Date operator+(int m);
    
    Date operator-(int m);

    Date operator+(Date& d);
    
    int operator-(Date d);
    
    bool operator>(Date d);
    bool operator>=(Date d);
    
    bool operator<=(Date d);
    
    bool operator<(Date d);
    
    bool operator!=(Date d);
    
    bool operator==(Date d);
    
    bool isLeapYear();
    
    char* ToString();

    void DateChecker();
    string stringconverter(int);
};