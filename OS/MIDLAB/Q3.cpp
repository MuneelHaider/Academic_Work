#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>
#include <mutex>
#include <sys/stat.h>
using namespace std;

/*

    Muneel Haider
    21i-0640
    LAB_MID - OS

*/

string bro;
mutex mute;

void* world(void* args){

    mute.lock();

    int result[26] = { 0 };
    char letter;
    char temp[bro.length()];

    for(int i = 0;i<bro.length();i++){

        temp[i] = bro[i];
    }

    int newFile = open(temp, O_RDONLY);

    while(read(newFile, &letter, 1) > 0){

        // write(newFile, &letter, 1);

        if(letter == '\n' || letter == ' '){

            continue;
        }

        result[letter - 'a'] += 1;

        cout << letter;
    }
    cout << endl;

    for(int i = 0; i < 26;i++){

        letter = i + 'a';

        cout << letter << " appears " << result[letter - 'a'] << " times." << endl;
    }

    pthread_exit(0);
}

int main(){

    pthread_t t1[10];

    char temp[50];
    cout << "Enter the name of your file: ";
    cin >> temp;
    cout << endl;
    bro = temp;

    for(int i = 0; i < 10; i++){

        pthread_create(&(t1[i]), NULL, world, NULL);
    }

    for(int i = 0; i < 10 ;i++){

        pthread_join(t1[i], NULL);
    }

    mute.unlock();
    pthread_exit(0);
}