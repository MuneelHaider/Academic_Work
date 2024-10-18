#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

/*
    Muneel Haider   
    21i-0640
    Class Task Lab 6    
*/

int main() {
    const char *path = "/tmp/myfifo";
    mkfifo(path, 0666);

    int o2 = open(path, O_WRONLY);

    if (o2 == -1) {
    
        printf("Error.");
        return 1;
    }

    while (true) {

        printf("Process 2: Type message to send to Process 1: ");

        char message[100];
        
        scanf("%s", message);
        write(o2, message, 100);
    }

    close(o2);
    unlink(path);
    return 0;
}














// #include <unistd.h>
// #include <stdio.h>
// #include <cstring>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// int main(){

//     const char* path = "/home/muneelhaider/Desktop/OS/LAB 6";
//     mkfifo(path, 0666);

//     int o2 = open(path, O_WRONLY);

//     if(o2 < 0){

//         printf("Error.");
//         exit(0);
//     }

//     while(true){

//         printf("Process 2: Message to send to Process 1: ");
//         char temp[200];
//         scanf("%s", temp);

//         write(o2, temp, 201);
//     }

//     close(o2);
//     unlink(path);
//     return 0;
// }


