#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Muneel Haider
    21i-0640
    Assignment 1 - PDC
    Question 1 - Randomizer
*/

int main() {

    FILE *file;

    srand(time(NULL));

    file = fopen("numbers.txt", "w");

    if (file == NULL) {

        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    for (int i = 0; i < 100000; i++) {

        fprintf(file, "%d ", rand() % 1000000 + 1); // Generate random number between 1 and 1,000,000
    }

    fclose(file);

    printf("Numbers generated and written to numbers.txt\n");

    return 0;
}
