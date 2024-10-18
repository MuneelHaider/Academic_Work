#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/*  
    Muneel Haider   
    21i-0640
    Assignment 2 - Q3
    Operating Systems
*/

int global;
int main(){

    int flag = 0;  
    int counter = 0; 
    char fakepath[200];
    char path[200];
    realpath("Q3.c", fakepath);

    for(int i = 199; i >= 0; i--){

        if(flag == 0 && fakepath[i - 1] == '.' && fakepath[i] == 'c'){

            flag = 1;
        }

        if(flag == 1){

            if((counter == 0 || counter == 1) && fakepath[i] == '/'){

                counter++;
            }

            if(counter == 2){

                fakepath[i + 1] = '\0';
                counter++;
            }

            if(counter == 3){
             
                path[i] = fakepath[i];
            }
        }
    }

    pid_t o1 = fork();
    if(o1 == 0){

        pid_t o2 = fork();

        if(o2 == 0){

            char *const argv[] = {"ls", "-l", path, NULL};
            execvp("ls", argv);

            printf("Child failed.\n");
        }
        else{

            wait(NULL);
        }
    }   
    else{
        
        wait(NULL);

        printf("Child successful\n");
    }

    return 0;
}