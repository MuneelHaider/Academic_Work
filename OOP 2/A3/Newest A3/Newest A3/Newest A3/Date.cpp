#include "pch.h"
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date() {

    year = 0;
    month = 0;
    day = 0;
}
Date::Date(int y, int m, int d) {

    if (m < 1 || m > 12) {

        m = 0;
    }
    if (d < 1) {

        d = 1;
    }

    year = y;
    month = m;
    day = d;

    if (year % 4 == 0) {

        leap = true;
    }
    else {

        leap = false;
    }
}

int Date::getYear() {

    return year;
}
void Date::setYear(int y) {

    year = y;
}

int Date::getMonth() {

    return month;
}
void Date::setMonth(int m) {

    month = m;
}

int Date::getDay() {

    return day;
}
void Date::setDay(int d) {

    day = d;
}

void Date::leaper() {

    if (this->year % 4 == 100) {

        leap = true;
    }
    else {

        leap = false;
    }
}

Date Date::operator=(Date& d) {

    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
    this->leaper();

    return *this;
}

Date Date::operator+(int m) {

    this->day += m;
    this->DateChecker();
    this->leaper();

    return *this;
}

Date Date::operator-(int m) {

    this->day -= m;
    this->DateChecker();
    this->leaper();

    return *this;
}

Date Date::operator+(Date& d) {

    Date obj;

    obj.year = this->year + d.year;
    obj.month = this->month + d.month;
    obj.day = this->day + d.day;

    obj.DateChecker();
    this->leaper();

    return obj;
}

int Date::operator-(Date d) {

    Date obj;

    obj.year = this->year - d.year;
    obj.month = this->month - d.month;
    obj.day = this->day - d.day - 1;

    obj.DateChecker();
    obj.leaper();

    int temp = obj.year;
    int temp1 = obj.month;

    while (temp > 0) {

        temp -= 1;
        obj.day += 365;
    }
    while (temp1 > 0) {

        temp1 -= 1;
        obj.day += 31;
    }

    return obj.day;
}

bool Date::operator>(Date d) {

    this->leaper();

    if (this->year > d.year) {

        return true;
    }

    if (this->year == d.year) {

        if (this->month > d.month) {

            return true;
        }

        if (this->month == d.month) {

            if (this->day > d.day) {

                return true;
            }
        }
    }
    return false;
}
bool Date::operator>=(Date d) {

    this->leaper();

    if (this->year > d.year) {

        return true;
    }

    if (this->year == d.year) {

        if (this->month > d.month) {

            return true;
        }

        if (this->month == d.month) {

            if (this->day >= d.day) {

                return true;
            }
        }
    }
    return false;
}

bool Date::operator<=(Date d) {

    this->leaper();

    if (this->year < d.year) {

        return true;
    }

    if (this->year == d.year) {

        if (this->month < d.month) {

            return true;
        }

        if (this->month == d.month) {

            if (this->day <= d.day) {

                return true;
            }
        }
    }
    return false;
}

bool Date::operator<(Date d) {

    this->leaper();

    if (this->year < d.year) {

        return true;
    }

    if (this->year == d.year) {

        if (this->month < d.month) {

            return true;
        }

        if (this->month == d.month) {

            if (this->day < d.day) {

                return true;
            }
        }
    }
    return false;
}

bool Date::operator!=(Date d) {

    this->leaper();

    if (this->year != d.year || this->month != d.month || this->day != d.day) {

        return true;
    }

    return false;
}

bool Date::operator==(Date d) {

    this->leaper();

    if (this->year == d.year && this->month == d.month && this->day == d.day) {

        return true;
    }

    return false;
}

bool Date::isLeapYear() {

    if (leap == true) {

        return true;
    }
    else {

        return false;
    }
}

char* Date::ToString() {

    string date = "";
    int index = 0;

    date = stringconverter(this->year);
    date += "/";

    if (this->month < 10) {

        date += "0";
    }

    date += stringconverter(this->month);
    date += "/";

    if (this->day < 0) {

        date += "0";
    }

    date += stringconverter(this->day);
    const int size = date.length();
    char* lol = new char[size];

    for (int i = 0; i < size; i++) {

        lol[i] = date[i];
    }
    lol[size] = '\0';

    return lol;
}

void Date::DateChecker() {

    if (this->day > 31) {

        this->day -= 31;
        this->month += 1;
    }

    if (this->month > 11) {

        this->month -= 12;
        this->year += 1;
    }

    if (this->day < 0) {

        this->day += 31;
        this->month -= 1;
    }
    if (this->month < 0) {

        this->month += 12;
        this->year -= 1;
    }

    if (this->year % 4 == 0) {

        leap = true;
    }
    else {

        leap = false;
    }

    this->leaper();
}

string Date::stringconverter(int value) {

    char result[20] = {};
    char lmao[20] = {};
    int temp = 0;
    int number = 0;
    int index = 0;
    int counter = 0;
    bool flag = false;

    while (value != 0 || index == 20) {

        temp = value % 10;
        value /= 10;
        result[index] = char(temp + 48);
        index++;
    }
    result[index] = '\0';

    counter = index - 1;

        for (int i = 0; i < index; i++) {

            lmao[i] = result[counter];
            counter--;
            temp = i;
        }
        lmao[temp + 1] = '\0';
 
    return lmao;
}