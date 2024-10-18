#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

sem_t sem;
int sharedVar = 0;

/*

    Muneel Haider
    21i-0640
    LAB 11
    Example

*/

void * functionB(void* ptr){

    int b;
    sem_wait(&sem); 

    b = sharedVar;
    b = b - 5;
    sharedVar = b;
    cout << "Shared Var from B: " << sharedVar << endl;

    sem_post(&sem); 
    pthread_exit(0);
}

void* functionA(void* ptr){

    int a;
    sem_wait(&sem);

    a = sharedVar;
    a = a + 10;
    sharedVar = a;
    cout << "Shared Var from A: " << sharedVar << endl;

    sem_post(&sem); 
    pthread_exit(0); 
}

int main() {

    sem_init(&sem, 0, 1);
    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, &functionA, NULL);
    pthread_create(&t2, NULL, &functionB, NULL);
    pthread_create(&t3, NULL, &functionA, NULL);
    pthread_create(&t4, NULL, &functionB, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    sem_destroy(&sem);

    pthread_exit(0);
}
