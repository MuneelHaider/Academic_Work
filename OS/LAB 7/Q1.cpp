#include <iostream>
#include <thread>
using namespace std;

/*      Muneel Haider   
        21i-0640        
        LAB 7           */

struct Item{

    int price;
    string name;
};

int totalBill = 0;
int tax = 0.18;
bool flags[6] = { false };

Item obj[6];

void BillCalculate(){

    for(int i = 0; i < 6; i++){

        if(flags[i] == true){

            totalBill += obj[i].price;
        }
    }
}

void AddTax(){

    float taxation = totalBill + (totalBill * tax);
    
    cout << "Total Bill after tax: " << taxation << endl;
}

int main(){

    obj[0].name = "Mango";
    obj[0].price = 10;
    obj[1].name = "Banana";
    obj[1].price = 20;
    obj[2].name = "Juice";
    obj[2].price = 30;
    obj[3].name = "Chips";
    obj[3].price = 40;
    obj[4].name = "Water";
    obj[4].price = 50;
    obj[5].name = "Chocolate";
    obj[5].price = 60;
    obj[6].name = "Pepsi";
    obj[6].price = 70;

    cout << "Items available: " << endl;
    for(int i = 0; i < 6; i++){

        cout << i + 1 << " " << obj[i].name << " - " << obj[i].price << endl;
    }

    int option = 20;

    while(option != 0){

        cout << "Select items to buy (1 - 6). Press 0 to finish." << endl;
        cin >> option;

        if(option == 0){

            break;
        }
        else if(option <= 0 || option >= 6){

            cout << "Incorrect choice. try again." << endl;
        }
        else{

            flags[option - 1] = true;
        }
    }

    thread t1(BillCalculate);
    t1.join();

    thread t2(AddTax);
    t2.join();
}