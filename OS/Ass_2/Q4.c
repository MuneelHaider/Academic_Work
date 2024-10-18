#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*  
    Muneel Haider   
    21i-0640
    Assignment 2 - Q4
    Operating Systems
*/

int main(){

    char* user = getenv("USER");
    char* path = getenv("PATH");
    char* term = getenv("TERM");

    char* var1 = "./script.sh";
    char* var2 = user;
    char* var3 = term;
    char* var4 = path;
    char* var5 = NULL;

    char* arg[] = {var1, var2, var3, var4, var5, NULL};

    char* OS = "OS2022-5ma32zw";
    char* environment[] = {OS, NULL};

    pid_t o1 = fork();

    if(o1 == 0){

        execve(var1, arg, environment);

        printf("\nExecve Failed.\n");
    }
    else{

        wait(NULL);

        printf("\n\n");
    }

    return 0;
}