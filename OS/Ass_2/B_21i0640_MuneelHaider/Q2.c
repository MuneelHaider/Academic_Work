#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/*  
    Muneel Haider   
    21i-0640
    Assignment 2 - Q2
    Operating Systems
*/

int global;
int main(){

    int newFile = open("output_bash.txt", O_WRONLY | O_CREAT | O_TRUNC);

    pid_t mainO = fork();
    pid_t id;
    pid_t id2;

    if(mainO == 0){ 

        id = getppid();
        id2 = getpid();
        printf("ID of main child: %d\n", id);

        pid_t o1 = fork();
        if(o1 == 0){

            id = getppid() - 1;
            printf("ID of parent (1st child): %d\n", id);
            printf("\n");

            int firstFile = open("file1.txt", O_RDONLY);
            char letter = 0;

            while(read(firstFile, &letter, 1) > 0){

                write(newFile, &letter, 1);
            }

            if(letter != '.'){

                write(newFile, ".", 1);
            }

            close(firstFile);
            exit(0);
        }
        else{

            wait(NULL);
        }

        id = getppid();
        printf("ID of parent (2nd child): %d\n", id);
        printf("\n");

        pid_t o2 = fork();
        if(o2 == 0){

            int secondFile = open("file2.txt", O_RDONLY);
            char letter = 0;

            while(read(secondFile, &letter, 1) > 0){

                write(newFile, &letter, 1);
            }

            if(letter != '.'){

                write(newFile, ".", 1);
            }

            close(secondFile);
            exit(0);
        }
        else{

            wait(NULL);
        }

        id = getppid();
        printf("ID of parent (3rd child): %d\n", id);
        printf("\n");

        pid_t o3 = fork();
        if(o3 == 0){

            int thirdFile = open("file3.txt", O_RDONLY);
            char letter = 0;

            while(read(thirdFile, &letter, 1) > 0){

                write(newFile, &letter, 1);
            }

            if(letter != '.'){

                write(newFile, ".", 1);
            }

            close(thirdFile);
            exit(0);
        }
        else{

            wait(NULL);
            exit(0);
        }
    }
    else{

        wait(NULL);
    }

    close(newFile);
    return 0;
}