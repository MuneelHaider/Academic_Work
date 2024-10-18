#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*  
    Muneel Haider   
    21i-0640
    Assignment 2 - Q6
    Operating Systems
*/

void printarray(char string[], int array[], int size){

    printf("%s Array:\n", string);
    for(int i = 0; i < size; i++){

        printf("%d, ", array[i]);
    }

    printf("\n\n");
}

void JoinArrays(int array[], int leftarray[], int rightarray[], int left, int right){

    int LeftIndex = 0;
    int RightIndex = 0;
    int ArrayIndex = 0;

    for(LeftIndex ; LeftIndex < left && RightIndex < right; LeftIndex += 0){

        if(rightarray[RightIndex] >= leftarray[LeftIndex]){

            array[ArrayIndex] = leftarray[LeftIndex];
            ArrayIndex += 1;
            LeftIndex += 1;
        }
        else if(rightarray[RightIndex] <= leftarray[LeftIndex]){

            array[ArrayIndex] = rightarray[RightIndex];
            ArrayIndex += 1;
            RightIndex += 1;
        }
    }

    for(LeftIndex; LeftIndex < left ; LeftIndex++){

        array[ArrayIndex] = leftarray[LeftIndex];
        ArrayIndex += 1;
    }

    for(RightIndex; RightIndex < right; RightIndex++){

        array[ArrayIndex] = rightarray[RightIndex];
        ArrayIndex += 1;
    }

    return;
}

void MergeAlgorithm(int array[], int size) {
    
    if (size < 2) {

        return;
    }

    int mid = size / 2;
    int aftermid = size - mid;
    
    int leftarray[mid];
    int rightarray[aftermid];

    int leftsize = sizeof(leftarray);
    int rightsize = sizeof(rightarray);

    for (int i = 0; i < mid; i++) {
    
        leftarray[i] = array[i];
    }
    
    for (int i = mid; i < size; i++) {
    
        rightarray[i - mid] = array[i];
    }

    int pl[2];
    int pr[2];
    
    pipe(pl);
    pipe(pr);

    pid_t o1 = fork();

    if (o1 == 0) {

        // Handles the left side of the original array
        MergeAlgorithm(leftarray, mid);
    
        write(pl[1], leftarray, leftsize);

        exit(0);
    } 
    else {

        pid_t o2 = fork();

        if (o2 == 0) {
        
            // Handles the right side of the original array
            MergeAlgorithm(rightarray, aftermid);
        
            write(pr[1], rightarray, rightsize);
        
            close(pr[1]);
            exit(0);
        } 
        else {
            
            // Waits for completion of sorting of both array sides
            wait(NULL);
            wait(NULL);

            read(pl[0], leftarray, leftsize);
            read(pr[0], rightarray, rightsize);

            // Joins the two arrays into one 'array'
            JoinArrays(array, leftarray, rightarray, mid, aftermid);
        }
    }
}

int main(){

    int array[] = {12, 34, 10, 6, 40, 8, 15, 23, 57, 19};
    int size = sizeof(array) / sizeof(array[0]);

    printarray("Real", array, size);

    MergeAlgorithm(array, size);

    printarray("Sorted", array, size);

    return 0;
}