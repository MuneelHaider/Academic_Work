#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main() {
    char input[100];  
    char output[100];

    int fd1[2];
    int fd2[2];

    pid_t p1;

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        cout << "pipe creation failed" << endl;
        return 1;
    }

    p1 = fork();
    if (p1 == 0) {
        close(fd1[1]);
        close(fd2[0]);
        while (true) {
            read(fd1[0], input, sizeof(input));
            if (input[0] == 'h') {
                write(fd2[1], "A", 1);
                break;
            } else {
                write(fd2[1], input, strlen(input) + 1);
            }
        }
        close(fd1[0]);
        close(fd2[1]);
        exit(0);
    } else {
        close(fd1[0]);
        close(fd2[1]);
        while (true) {
            cout << "Enter string: ";
            cin.getline(input, sizeof(input));
            write(fd1[1], input, strlen(input) + 1);
            read(fd2[0], output, sizeof(output));
            if (output[0] == 'A') {
                cout << "Received from child: A" << endl;
cout << "EXITING PROGRAM ....." << endl;
                break;
            } else {
                cout << "Received from child: " << output << endl;
            }
        }
        close(fd1[1]);
        close(fd2[0]);
        wait(nullptr);
    }

    return 0;
}