#include <iostream>
using namespace std;

class instructor {

    string name;
    string last_name;
    string office_num;

public:

    instructor() {

        name = "";
        last_name = "";
        office_num = "";
    }

    instructor(string nameVal, string lastVal, string officeVal) {

        name = nameVal;
        last_name = lastVal;
        office_num = officeVal;
    }

    void setInstructor(string nameVal, string lastVal, string officeVal) {

        name = nameVal;
        last_name = lastVal;
        office_num = officeVal;
    }

    void printInstructor() {

        cout << "Professor's Information:" << endl;
        cout << "First Name:    " << name << endl;
        cout << "Last Name:     " << last_name << endl;
        cout << "Office Number: " << office_num << endl << endl;
    }
};

class TextBook {

    string title;
    string author;
    string publisher;

public:

    TextBook() {

        title = "";
        author = "";
        publisher = "";
    }

    TextBook(string titleVal, string authorVal, string publisherVal) {

        title = titleVal;
        author = authorVal;
        publisher = publisherVal;
    }

    void setTextBook(string titleVal, string authorVal, string publisherVal) {

        title = titleVal;
        author = authorVal;
        publisher = publisherVal;
    }

    void printTextBook() {

        cout << "Textbook Information:" << endl;
        cout << "Title:     " << title << endl;
        cout << "Author:    " << author << endl;
        cout << "Publisher: " << publisher << endl << endl;
    }
};

class Course {

    string c_name;
    instructor professor;
    TextBook book;

public:

    Course() {

        c_name = "";

        professor.setInstructor("", "", "");
        book.setTextBook("", "", "");
    }

    Course(string c_nameVal, string nameVal, string lastVal, string officeVal, string titleVal, string authorVal, string publisherVal) {

        c_name = c_nameVal;

        professor.setInstructor(nameVal, lastVal, officeVal);
        book.setTextBook(titleVal, authorVal, publisherVal);
    }

    void printCourse() {

        cout << "Course: " << c_name << endl << endl;

        professor.printInstructor();
        book.printTextBook();
    }

};

int main() {
    
    Course obj("OOP", "Sami Ullah", "Shah", "03088828430", "Introduction to OOP", "Sir", "Saeed Publishers");

    obj.printCourse();

    return 0;
}