#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
    Muneel Haider
    21i-0640
    Assignment 1 - PDC
    Question 1 - Serial Version
*/

struct node {

    int number;
    node* next;
};

const int size = 100000;

void printLinkedList(node* head) {
    
    node* current = head;
    int counter = 0;

    while (current != NULL) {
    
        printf("%d, ", current->number);
        current = current->next;
        counter++;
    }

    printf("\n\nIt read %d numbers. \n\n", counter);
}

void readNumbers(FILE* reader, int* array) {
    
    for (int i = 0; i < size; i++) {
    
        fscanf(reader, "%d", &array[i]);
    }
}

void addToLinkedList(node** head, int* array) {
    
    node* current;
    node* latest = NULL;

    for (int i = 0; i < size; i++) {
    
        current = (node*)malloc(sizeof(node));

        if (current == NULL) {
    
            printf("New pointer not created. \n");
            exit(1);
        }

        current->number = array[i];

        if (*head == NULL) {
    
            *head = current;
        } 
        else {
    
            latest->next = current;
        }

        latest = current;
    }
}

node* mergeAlgo(node* left, node* right) {
    
    if (left == NULL) {
    
        return right;
    } 
    else if (right == NULL) {
    
        return left;
    }

    node* current = NULL;

    if (left->number <= right->number) {
       
        current = left;
        current->next = mergeAlgo(left->next, right);
    } 
    else {
     
        current = right;
        current->next = mergeAlgo(left, right->next);
    }

    return current;
}

node* mergeSorter( node* head) {

    if (head == NULL || head->next == NULL) {

        return head;
    }

    node* halfOne = head;
    node* halfTwo = head->next;

    while (halfTwo != NULL && halfTwo->next != NULL) { 

        halfOne = halfOne->next;
        halfTwo = halfTwo->next->next;
    }

    node* rightHalf = halfOne->next;
    halfOne->next = NULL;

    node* leftSorted = mergeSorter(head);
    node* rightSorted = mergeSorter(rightHalf);

    return mergeAlgo(leftSorted, rightSorted);
}

int main() {
    
    // Time calculation
    struct timeval start_time;
    struct timeval end_time;
    double time;

    gettimeofday(&start_time, NULL);

    char* filename = "numbers.txt";
    
    FILE* reader = fopen(filename, "r");

    if (reader == NULL) {
    
        printf("Error opening file. \n");
        exit(1);
    }

    int array[size];
    
    readNumbers(reader, array);
    
    fclose(reader);

    node* head = NULL;

    addToLinkedList(&head, array);

    printf("This is the LinkedList without applying merge sort:\n\n");
    printLinkedList(head);

    head = mergeSorter(head);

    printf("\n\n\nThis is the LinkedList after applying merge sort:\n\n");
    printLinkedList(head);
    
    // Time calculation
    gettimeofday(&end_time, NULL);

    time = ((end_time.tv_sec - start_time.tv_sec) * 1000.0);
    time += ((end_time.tv_usec - start_time.tv_usec) / 1000) + 500;
    printf("Execution time: %.2f milliseconds\n", time);

    return 0;
}