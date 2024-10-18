#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;

class Student {

    int id;
    char Name[100], Father_name[200], Address[200], CNIC[200];

public:

    Student() {

        id = 0;
        *Name = '\0';
        *Father_name = '\0';
        *Address = '\0';
        *CNIC = '\0';
    }

    Student(int idVal, char NameVal[], char FatherVal[], char AddressVal[], char CNICval[]) {

        id = idVal;

        int i = 0;

        while(*(NameVal + i) != '\0') {

            Name[i] = NameVal[i];
            i++;
        }
        Name[i] = '\0';

        i = 0;
        while (FatherVal[i] != '\0') {

            Father_name[i] = FatherVal[i];
            i++;
        }
        Father_name[i] = '\0';

        i = 0;
        while (AddressVal[i] != '\0') {

            Address[i] = AddressVal[i];
            i++;
        }
        Address[i] = '\0';

        i = 0;
        while (CNICval[i] != '\0') {

            CNIC[i] = CNICval[i];
            i++;
        }
        CNIC[i] = '\0';
    }

    void setid(int idVal = 0) {

        id = idVal;
    }
    void setName(char* NameVal) {

        for (int i = 0; *(NameVal + i) != '\0'; i++) {

            Name[i] = NameVal[i];
        }
    }
    void setFather_Name(char* FatherVal) {

        for (int i = 0; *(FatherVal + i) != '\0'; i++) {

            Father_name[i] = FatherVal[i];
        }
    }
    void setAddress(char* AddVal) {

        for (int i = 0; *(AddVal + i) != '\0'; i++) {

            Address[i] = AddVal[i];
        }
    }
    void setCNIC(char* CNICval) {

        for (int i = 0; *(CNICval + i) != '\0'; i++) {

            CNIC[i] = CNICval[i];
        }
    }

    int getid() {

        return id;
    }
    char* getName() {

        return Name;
    }
    char* getFatherName() {

        return Father_name;
    }
    char* getAddress() {

        return Address;
    }
    char* getCNIC() {

        return CNIC;
    }
         
    
    void Write(Student obj, string file_name) {
        
        bool flag = true;
        ofstream File(file_name, ios::binary | ios::out);

        if (File) {

            flag = true;
            File.write((char*)& obj, sizeof(obj));
            File.close();
        }
        else {

            cout << "Unable to open and append file." << endl;
            flag = false;
        }
    }

    void Display() {

        cout << id << endl;
        cout << Name << endl;
        cout << Father_name << endl;
        cout << Address << endl;
        cout << CNIC << endl << endl;
    }

    void Read(string file_name) {

        Student temp;
        bool flag = true;

        ifstream File(file_name, ios::binary | ios::in);

        if (File) {

            flag = true;
            File.read((char*)&temp, sizeof(temp));
            temp.Display();
            File.close();
        }
        else {

            cout << "Unable to open file." << endl << endl;
        }
    }
};

int main() {

    int id               = 640;
    char Name[10]        = "Muneel";
    char Father_Name[10] = "Raza";
    char Address[10]     = "Islamabad";
    char CNIC[10]        = "61101";

    Student MuneelHaider(id, Name, Father_Name, Address, CNIC);

    Student temp;
    temp.Write(MuneelHaider, "file.bin");
    temp.Read("file.bin");
}