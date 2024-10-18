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

int main(int argc, char* argv[]){

    for(int i = 0;i < argc;i++){

        printf("Argument %d : %s \n", i, argv[i]);
    }
}