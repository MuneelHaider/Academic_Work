#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex;
int sharedVar = 0;

void * functionB(void* ptr){

    int b;
    pthread_mutex_lock(&mutex);

    b = sharedVar;

    b = b - 5;
    sharedVar = b;
    cout << "Shared Var from B: " << sharedVar << endl;

    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

void* functionA(void* ptr){

    int a;
    pthread_mutex_lock(&mutex);
    a=sharedVar;

    a = a + 10;
    sharedVar = a;
    cout << "Shared Var from A: " << sharedVar << endl;

    pthread_mutex_unlock(&mutex);
    pthread_exit(0); 
}



int main(){

    pthread_mutex_init(&mutex, NULL);
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, &functionA, NULL);
    pthread_create(&t2, NULL, &functionB, NULL);
    pthread_create(&t3, NULL, &functionA, NULL);
    pthread_create(&t4, NULL, &functionB, NULL);

    pthread_mutex_destroy(&mutex);

    pthread_exit(0);
}