#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
using namespace std;


// Muneel Haider
// 21i-0640


// Example EXECL
int main(){

    pid_t childpid = fork();

    if(childpid == 0){

        printf("I am child process with pid = %d \n", getpid());
        printf("The next statement is execel and ls will \n");
        
        execl("/bin/ls" ,"ls", "-1", "/usr", NULL);
        
        printf("Execl Failed \n");
        
    }
    else if(childpid > 0){

        wait(NULL);
        printf("\nI am parent process with pid = %d and finished waiting \n", getpid());
    }

    return 0;
}