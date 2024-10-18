#pragma once
#include <iostream>

class Student {

public:

    string Batch;
    string Designation;

    Student(string BVal = NULL, string DesVal = NULL) {

        Batch = BVal;
        Designation = DesVal;
    }

    string getBatch() {

        return Batch;
    }
    void setBatch(string BVal) {

        this->Batch = BVal;
    }

    string getDesignation() {

        return Designation;
    }
    void setDesignation(string DesVal) {

        this->Designation = DesVal;
    }
};

class Staff {

public:

    string Dept;
    string Designation;

    Staff(string DeptVal = NULL, string DesVal = NULL) {

        Dept = DeptVal;
        Designation = DesVal;
    }

    string getDept() {

        return Dept;
    }
    void setDept(string DeptVal) {

        this->Dept = DeptVal;
    }

    string getDesignation() {

        return Designation;
    }
    void setDesignation(string DesVal) {

        this->Designation = DesVal;
    }
};

class Account {

public:

    int no_borrowed_books;
    int no_lost_books;
    int no_reserved_book;
    float fine_amount;

    int getborrow() {

        return no_borrowed_books;
    }
    void setborrow(int Val) {

        no_borrowed_books = Val;
    }

    int getlost() {

        return no_lost_books;
    }
    void setlost(int Val) {

        no_lost_books = Val;
    }

    int getreserved() {

        return no_reserved_book;
    }
    void setreserved(int Val) {

        no_reserved_book = Val;
    }

    int getfine() {

        return fine_amount;
    }
    void setfine(int Val) {

        fine_amount = Val;
    }

    Account(int borrowVal = 0, int lostVal = 0, int reservedVal = 0, int fineVal = 0) {

        no_borrowed_books = borrowVal;
        no_lost_books = lostVal;
        no_reserved_book = reservedVal;
        fine_amount = fineVal;
    }

    float Calculate_fine(int lostVal) {

        float fine = 50.56;

        float total = lostVal * fine;

        return total;
    }
};

class User : protected Student, protected Staff {

public:

    string Name;
    int ID;
    Account acc;

    User(string NameVal = NULL, int IDVal = 0) {

        Name = NameVal;
        ID = IDVal;
    }

    string getName() {

        return Name;
    }
    void setName(string NameVal) {

        this->Name = NameVal;
    }

    int getID() {

        return ID;
    }
    void setID(int IDVal) {

        this->ID = IDVal;
    }

    bool Verify(string NameVal, int IDVal) {

        bool flag1 = true;
        bool flag2 = true;

        if (NameVal == this->Name) {

            flag1 = true;

            if (IDVal == this->ID) {

                flag2 = true;
            }
            else {

                flag2 = false;
            }
        }
        else {

            flag1 = false;
        }

        if (flag1) {

            if (flag2) {

                return true;
            }
            else {
                return false;
            }
        }
        else {

            return false;
        }
    }

    bool Check_account(Account acc) {

        if (acc.getborrow() == 0 && acc.getlost() == 0 && acc.getreserved() == 0 && acc.getfine() == 0) {

            return true;
        }
        else {

            return false;
        }
    }

    void get_book_info() {

        cout << "Borrowed amount of books   " << acc.getborrow() << endl;
        cout << "Reserved amount of books:  " << acc.getreserved() << endl;
        cout << "Lost amount of books:      " << acc.getlost() << endl;
        cout << "Fine amount due to pay:    " << acc.getfine() << endl << endl;
    }
};

class Library_database {

public:


    Account account;


};

class Page {

public:

    string text;
    int Page_no;

    Page(string textVal = NULL, int PageVal = 0) {

        text = textVal;
        Page_no = PageVal;
    }

    string gettext() {

        return text;
    }
    void settext(string textVal) {

        this->text = textVal;
    }

    int getPage() {

        return Page_no;
    }
    void setPage(int PageVal) {

        this->Page_no = PageVal;
    }
};

class Book {

public:

    string Title;
    string Author;
    string ISBN;
    Page page;

    Book(string TVal = NULL, string AVal = NULL, string ISBNval = NULL) {

        Title = TVal;
        Author = AVal;
        ISBN = ISBNval;
    }
};