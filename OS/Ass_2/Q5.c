#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

/*  
    Muneel Haider   
    21i-0640
    Assignment 2 - Q5
    Operating Systems
*/

void decrypt(char filename[], char path[], char oldfile[], char realfile[]){

    strcat(oldfile, path);
    strcat(oldfile, filename);
    strcat(realfile, path);
    strcat(realfile, filename);

    for(int i = 0; realfile[i] != '\0'; i++){

        if(realfile[i] == '.' && realfile[i + 1] == 'e'){

            realfile[i] = '\0';
            break;
        }
    }

    char newshit[62] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    char original[62] = {'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','5','6','7','8','9','0','1','2','3','4'};

    int file = open(oldfile, O_RDONLY);
    int newfile = open(realfile, O_WRONLY | O_CREAT | O_TRUNC);

    int readCheck;
    char letter;

    while(readCheck = read(file, &letter, 1) > 0){

        int check2 = 0;

        for(int i = 0; i < 62; i++){

            if(letter == original[i]){

                write(newfile, &newshit[i], 1);
                check2 = 1;
                break;
            }
        }

        if(check2 == 0){

            write(newfile, &letter, 1);
        }
    }
}

void encrypt(char filename[], char path[], char oldfile[], char realfile[]){

    strcat(realfile, path);
    strcat(realfile, filename);
    strcat(oldfile, path);
    strcat(oldfile, filename);
    strcat(realfile, ".enc");

    char original[62] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    char newshit[62] = {'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','5','6','7','8','9','0','1','2','3','4'};

    int file = open(oldfile, O_RDONLY);
    int newfile = open(realfile, O_WRONLY | O_CREAT | O_TRUNC);

    char letter;
    int readCheck;

    while(readCheck = read(file, &letter, 1) > 0){

        int check2 = 0;

        for(int i = 0; i < 62; i++){

            if(letter == original[i]){

                write(newfile, &newshit[i], 1);
                check2 = 1;
                break;
            }
        }

        if(check2 == 0){

            write(newfile, &letter, 1);
        }
    }
}

int global;
int main(){

    char fakepath[200];
    char path[200];
    char files[50][200];

    printf("\nEnter directory path (Add / at the end of given path):\n");
    scanf("%s", path);

    DIR* directory = opendir(path);
    struct dirent* entry;

    int countFiles;
    for(countFiles = 0; entry = readdir(directory); countFiles){

        if(entry->d_name[0] != '.'){

            strcpy(files[countFiles], entry->d_name);
            countFiles++;
        }
    }

    // Asks to choose files
    printf("\nPlease choose which files to encrypt:\n");
    for(int i = 0; i<countFiles; i++){

        printf("%d ", i);
        printf("%s\n", files[i]);
    }

    // Seperates the input into an chosenFiles, here indexes are saved
    int wordIndex = 0;
    int charIndex = 0;
    char chosenFiles[20][200];
    char chosenNumbers[20];
    scanf(" %[^\n]", chosenNumbers);

    for(int i = 0; chosenNumbers[i] != '\0'; i++){

        if(chosenNumbers[i] != ' '){

            chosenFiles[wordIndex][charIndex] = chosenNumbers[i];
            charIndex++;
        }
        else{

            chosenFiles[wordIndex][charIndex] = '\0';
            wordIndex++;
            charIndex = 0;
        }
    }

    if(charIndex > 0){

        chosenFiles[wordIndex][charIndex] = '\0';
    }

    for(int i = 0; i <= wordIndex; i++){

        printf("Chosen %d: %s\n", i, chosenFiles[i]);
    }

    int option1 = 0;
    printf("\nSelect option:\n");
    printf("1. Encrypt.\n");
    printf("2. Decrypt.\n");

    scanf("%d", &option1);
    
    // Use saved indexes in chosenFiles to access files[i] and start excryption/decryption
            
    if(option1 == 1){

        pid_t o1 = fork();

        if(o1 == 0){

            for(int i = 0;i <= wordIndex; i++){

                char oldfile[200] = {};
                char realfile[200] = {};

                printf("\n");
                encrypt(files[atoi(chosenFiles[i])], path, oldfile, realfile);
            }
        }
        else{

            wait(NULL);
        }
    }
    else if(option1 == 2){

        pid_t o1 = fork();
        
        if(o1 == 0){

            for(int i = 0;i <= wordIndex; i++){

                char oldfile[200] = {};
                char realfile[200] = {};

                printf("\n");
                decrypt(files[atoi(chosenFiles[i])], path, oldfile, realfile);
            }
        }
        else{

            wait(NULL);
        }
    }
    else{

        printf("\nWrong option. Program finished.");
    }
    
    printf("\n\n\n");
    return 0;
}