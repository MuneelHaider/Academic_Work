#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <mutex>
#include <sys/stat.h>
using namespace std;

/*

    Muneel Haider
    21i-0640
    LAB_MID - OS

*/

string reverse(string hell){

    int s = hell.length();
    int counter = 0;
    char temp[s];

    for(int i = s - 1; i>=0;i--){

        temp[counter] = hell[i];
        counter++;
    }

    return temp;
}
int bro;
string hello;
string sorter(string Var){

    int s = Var.length();
    char res;

    for(int i = 0;i < s;i++){
        for(int j = 0; j < s;j++){

            if(Var[i] < Var[j]){

                res = Var[i];
                Var[i] = Var[j];
                Var[j] = res;
            }
        }
    }

    return Var;
}

void* add2(void* args){

    hello[bro] += 2;

    pthread_exit(0);
}

int main(){

    string temp;
    cout << "Please enter string: ";
    cin >> temp;
    
    string result;

    int status = 0, size = 0;

    pthread_t firstChild, secondChild;

    int fd[2];

    firstChild = fork();

    if(firstChild == 0){

        cout << "Original String: " << temp << endl;
        
        hello = reverse(temp);
        result = hello;

        close(fd[0]);
        // bro = write(fd[1], (void*)hello, temp.length());

        cout << "Reverse String: " << result << endl;

        pthread_exit(0);
    }
    else if(firstChild > 0){

        wait(&status);
        secondChild = fork();

        close(fd[1]);
        // hello = read(fd[0], hello, bro);

        if(secondChild < 0){

            cout << "Fork 2 failed.";
        }
        else if(secondChild == 0){

            size = temp.length();

            exit(size);
        }
        else{

            wait(&status);
            status = temp.length();

            cout << "Length: " << status << endl;

            size = temp.length();
            hello = reverse(temp);


            pthread_t thread[size];

            for(int i = 0;i < size;i++){

                bro = i - 1;
                pthread_create(&(thread[i]), NULL, add2, (void*)i);
            }

            for(int i = 0; i < size; i++){

                pthread_join((thread[i]), NULL);
            }

            cout << "After adding 2: " << hello << endl;

            cout << "After sorting: " << sorter(hello) << endl;
        }
    }
    else{

        cout << "Fork Failed." << endl;
    }

    pthread_exit(0);
}