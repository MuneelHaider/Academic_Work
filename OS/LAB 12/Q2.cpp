#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define CARBON_THREADS 2
#define OXYGEN_THREADS 6

/*

    Muneel Haider
    21i-0640
    LAB 12
    Task 2

*/

sem_t carbon_sem;
sem_t oxygen_sem;

pthread_mutex_t print_mutex;

void signal_molecule(sem_t *molecule_sem, int count) {

    for (int i = 0; i < count; ++i) {

        sem_post(molecule_sem);
    }
}

void* scientist(void *id) {

    int scientist_id = *(int *)id;

    while (1) {

        pthread_mutex_lock(&print_mutex);

        printf("Scientist %d is waiting for molecules to become available.\n", scientist_id);
        pthread_mutex_unlock(&print_mutex);
        
        signal_molecule(&carbon_sem, 2);
        signal_molecule(&oxygen_sem, 6);
        
        sleep(2);

        pthread_mutex_lock(&print_mutex);
        
        printf("Scientist %d creates a Carbon Dioxide molecule.\n", scientist_id);
        
        pthread_mutex_unlock(&print_mutex);
    }
    
    return NULL;
}

void* carbon_thread(void *id) {
    
    while (1) {
    
        sem_wait(&carbon_sem);
    
        pthread_mutex_lock(&print_mutex);
        printf("Carbon Thread %ld becomes idle.\n", (long)id);
    
        pthread_mutex_unlock(&print_mutex);
        
        printf("Carbon Thread %ld signals Scientist.\n", (long)id);
        
        sleep(1);
    }
    
    return NULL;
}

void* oxygen_thread(void *id) {
    
    while (1) {
    
        sem_wait(&oxygen_sem);
        pthread_mutex_lock(&print_mutex);
    
        printf("Oxygen Thread %ld becomes idle.\n", (long)id);
        pthread_mutex_unlock(&print_mutex);
        
        printf("Oxygen Thread %ld signals Scientist.\n", (long)id);
        
        sleep(1);
    }
    
    return NULL;
}

int main() {
    
    int run_time;
    
    printf("Enter the number of seconds the program will run: ");
    scanf("%d", &run_time);
    
    sem_init(&carbon_sem, 0, 0);
    sem_init(&oxygen_sem, 0, 0);
    
    pthread_mutex_init(&print_mutex, NULL);
    
    pthread_t scientist_threads[3];
    
    int scientist_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
    
        pthread_create(&scientist_threads[i], NULL, scientist, &scientist_ids[i]);
    }

    pthread_t carbon_threads[CARBON_THREADS];
    pthread_t oxygen_threads[OXYGEN_THREADS];

    for (long i = 0; i < CARBON_THREADS; i++) {
    
        pthread_create(&carbon_threads[i], NULL, carbon_thread, (void *)i);
    }

    for (long i = 0; i < OXYGEN_THREADS; i++) {
    
        pthread_create(&oxygen_threads[i], NULL, oxygen_thread, (void *)i);
    }

    sleep(run_time);

    for (int i = 0; i < 3; i++) {
    
        pthread_cancel(scientist_threads[i]);
    }
    
    for (int i = 0; i < CARBON_THREADS; i++) {
    
        pthread_cancel(carbon_threads[i]);
    }
    
    for (int i = 0; i < OXYGEN_THREADS; i++) {
    
        pthread_cancel(oxygen_threads[i]);
    }

    sem_destroy(&carbon_sem);
    sem_destroy(&oxygen_sem);
    
    pthread_mutex_destroy(&print_mutex);

    pthread_exit(0);
}
