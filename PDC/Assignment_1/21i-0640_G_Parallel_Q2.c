#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

/*
    Muneel Haider
    21i-0640
    Assignment 1 - PDC
    Question 1 - Serial Version
*/

const int threadsForList = 4;
const int size = 100000;
const int threadsForMerge = log2(size);

struct node {

    int number;
    struct node* next;
};

int array[size];
struct node* head = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* addToLinkedList(void* arg) {

    int* segment_start = (int*)arg;

    for (int i = 0; i < size / threadsForList; i++) {

        struct node* new_node = (struct node*)malloc(sizeof(struct node));

        if (new_node == NULL) {

            perror("Error creating node");
            exit(EXIT_FAILURE);
        }

        new_node->number = segment_start[i];
        new_node->next = NULL;

        pthread_mutex_lock(&mutex);

        new_node->next = head;
        head = new_node;

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void printLinkedList(struct node* head) {

    struct node* current = head;
    int counter = 0;

    while (current != NULL) {

        printf("%d, ", current->number);
        current = current->next;
        counter++;
    }

    printf("\n\nIt read %d numbers. \n\n", counter);
}

void readNumbers(FILE* reader) {

    for (int i = 0; i < size; i++) {

        fscanf(reader, "%d", &array[i]);
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

node* mergeSorter(node* head) {

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

void* mergeSorterThreader(void* args){
   
}

void setAffinity(pthread_t thread, int coreId) {

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(coreId, &cpuset);
    pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
}


int main() {

    // Time calculation
    struct timeval start_time;
    struct timeval end_time;
    double time;

    gettimeofday(&start_time, NULL);

    const char* filename = "numbers.txt";
    FILE* reader = fopen(filename, "r");

    if (reader == NULL) {
        printf("Error opening file. \n");
        exit(1);
    }

    readNumbers(reader);
    fclose(reader);

    pthread_t threads[threadsForList];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < threadsForList; i++) {
       
        int* segment_start = &array[i * (size / threadsForList)];
        pthread_create(&threads[i], &attr, addToLinkedList, (void*)segment_start);
        setAffinity(threads[i], i);
    }

    for (int i = 0; i < threadsForList; i++) {
        
        pthread_join(threads[i], NULL);
    }

    pthread_t threadsMerge[threadsForMerge];
    pthread_attr_t attr1;
    pthread_attr_init(&attr1);
    pthread_attr_setdetachstate(&attr1, PTHREAD_CREATE_JOINABLE);

    for(int i = 0; i < threadsForMerge; i++){

        pthread_create(&threadsMerge[i], NULL, mergeSorterThreader, (void*)head);
        setAffinity(threadsMerge[i], i);
    }

    for(int i = 0; i < threadsForMerge; i++){

        pthread_join(threadsMerge[i], NULL);
        head = mergeSorter(head);
    }
    
    printLinkedList(head);

    gettimeofday(&end_time, NULL);

    time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    time += (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    printf("Execution time: %.2f milliseconds\n", time);

    return 0;
}