#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*  
    Muneel Haider   
    21i-0640
    Assignment 2 - Q1
    Operating Systems
*/

int global;
int main(){

    pid_t id = getpid();
    pid_t id2 = getppid();

    printf("P1\n");
    printf("Process id of main process: %d\n", id);
    printf("\n");

    pid_t o1 = fork();
    // pid_t id;
    // pid_t id2;

    if(o1 == 0){

        id = getpid();
        id2 = getppid();
        printf("P3\n");
        printf("Process id of this (1st child) process: %d\n", id);
        printf("Process id of parent (1st child) process: %d\n", id2);
        printf("\n");

        exit(0);
    }
    else if(o1 > 0) {

        wait(NULL);
        WEXITSTATUS(global);

        id = getpid();
        id2 = getppid();
        printf("P2 (basically P1)\n");
        printf("Process id of this (1st parent) process: %d\n", id);
        printf("Process id of parent (1st parent) process: %d\n", id2);      
        printf("\n");  

        pid_t o2 = fork();

        if(o2 == 0){

            id = getpid();
            id2 = getppid();
            printf("P5\n");
            printf("Process id of this (2nd child) process: %d\n", id);
            printf("Process id of parent (2nd child) process: %d\n", id2);
            printf("\n");

            exit(0);
        }
        else if(o2 > 0) {

            wait(NULL);
            WEXITSTATUS(global);

            id = getpid();
            id2 = getppid();
            printf("P4 (basically P1)\n");
            printf("Process id of this (2nd parent) process: %d\n", id);
            printf("Process id of parent (2nd parent) process: %d\n", id2);
            printf("\n");

            exit(0);
        }
    }

    return 0;
}