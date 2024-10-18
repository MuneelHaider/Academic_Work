#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <unistd.h> 

/*

    Muneel Haider
    21i-0640
    LAB 12
    Task 1

*/

typedef struct BakeryLock {

    int choosing[10];
    int number[10];
    pthread_mutex_t mutex;

} BakeryLock;

typedef struct ThreadArg {

    int thread_id;
    BakeryLock *lock;

} ThreadArg;

void lock_init(BakeryLock *lock) {

    for (int i = 0; i < 10; i++) {

        lock->choosing[i] = 0;
        lock->number[i] = 0;
    }

    pthread_mutex_init(&lock->mutex, NULL);
}

void lock_acquire(BakeryLock *lock, int thread_id) {

    pthread_mutex_lock(&lock->mutex);

    lock->choosing[thread_id] = 1;
    int max = 0;

    for (int i = 0; i < 10; i++) {

        int num = lock->number[i];
        max = num > max ? num : max;
    }

    lock->number[thread_id] = max + 1;
    lock->choosing[thread_id] = 0;

    pthread_mutex_unlock(&lock->mutex);

    for (int i = 0; i < 10; i++) {

        if (i == thread_id) continue;

        while (lock->choosing[i]) {}

        while (lock->number[i] != 0 && (lock->number[i] < lock->number[thread_id] || (lock->number[i] == lock->number[thread_id] && i < thread_id))) {}
    }
}

void lock_release(BakeryLock *lock, int thread_id) {

    pthread_mutex_lock(&lock->mutex);
    
    lock->number[thread_id] = 0;
    
    pthread_mutex_unlock(&lock->mutex);
}

void* thread_func(void *arg) {
    
    ThreadArg *thread_arg = (ThreadArg*)arg;
    
    int thread_id = thread_arg->thread_id;
    
    BakeryLock *lock = thread_arg->lock;

    printf("Thread %d is waiting to acquire the lock...\n", thread_id);
    lock_acquire(lock, thread_id);

    printf("Thread %d has entered the critical section\n", thread_id);
    sleep(2);

    lock_release(lock, thread_id);
    printf("Thread %d has released the lock and exited the critical section\n", thread_id);
    
    return NULL;
}

int main() {
    
    pthread_t threads[10];
    ThreadArg args[10];
    
    BakeryLock lock;
    lock_init(&lock);

    for (int i = 0; i < 10; i++) {
    
        args[i].thread_id = i;
        args[i].lock = &lock;
    
        if (pthread_create(&threads[i], NULL, thread_func, &args[i])) {
    
            fprintf(stderr, "Error creating thread\n");
    
            return 1;
        }
    }

    for (int i = 0; i < 10; i++) {
    
        if (pthread_join(threads[i], NULL)) {
    
            fprintf(stderr, "Error joining thread\n");
    
            return 2;
        }
    }

    pthread_mutex_destroy(&lock.mutex);
    
    pthread_exit(0);
}