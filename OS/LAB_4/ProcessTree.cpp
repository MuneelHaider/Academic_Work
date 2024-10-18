#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

int i = 0;

int main() {

    cout << i << endl;
    fork();

    i = i + 1;
    
    cout << i << endl;
    
    if(fork() || fork() && fork()) {

        fork() && fork() || fork();
        i += 1;
        cout << "I am here." << endl;

    }

    cout << endl;

}