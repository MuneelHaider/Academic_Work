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

    int o1 = open(path, O_RDONLY);
    
    if (o1 == -1) {
    
        printf("Error.\n");
        return 1;
    }

    while (true) {

        char message[100];

        int reader = read(o1, message, sizeof(message));
        
        if (reader <= 0) {
        
            perror("read");
            break;
        }

        printf("Process 1: Message from Process 2 is: %s\n", message);
    }

    close(o1);
    unlink(path);
    return 0;
}
