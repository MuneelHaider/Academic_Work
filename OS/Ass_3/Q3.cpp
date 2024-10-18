#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/*

    Muneel Haider
    21i-0640
    Assignment 3
    Question 3

*/

#define totalPhilosophers (2 * 3)

typedef struct {

    int philosopherId;
    int tableId;
    sem_t* forks;
    int totalSeats;

} Philosopher;

sem_t tableForks[2][3];

void pickUpForks(Philosopher* philosopher, int leftFork, int rightFork) {

    if (leftFork < rightFork) {

        sem_wait(&philosopher->forks[leftFork]);
        sem_wait(&philosopher->forks[rightFork]);

    } else {

        sem_wait(&philosopher->forks[rightFork]);
        sem_wait(&philosopher->forks[leftFork]);
    }
}

void putDownForks(Philosopher* philosopher, int leftFork, int rightFork) {

    sem_post(&philosopher->forks[leftFork]);
    sem_post(&philosopher->forks[rightFork]);
}

void* philosopherRoutine(void* arg) {

    Philosopher* philosopher = (Philosopher*)arg;

    int leftFork = philosopher->philosopherId % philosopher->totalSeats;
    int rightFork = (philosopher->philosopherId + 1) % philosopher->totalSeats;

    while (true) {

        printf("Philosopher %d at Table %d is thinking.\n", philosopher->philosopherId, philosopher->tableId);
        sleep(3);

        printf("Philosopher %d at Table %d is hungry and trying to pick up forks %d and %d.\n", philosopher->philosopherId, philosopher->tableId, leftFork, rightFork);
        pickUpForks(philosopher, leftFork, rightFork);

        printf("Philosopher %d at Table %d is eating.\n", philosopher->philosopherId, philosopher->tableId);
        sleep(3);
        
        printf("Philosopher %d at Table %d finished eating and is putting down forks %d and %d.\n", philosopher->philosopherId, philosopher->tableId, leftFork, rightFork);
        putDownForks(philosopher, leftFork, rightFork);
    }

    return NULL;
}

int main() {

    pthread_t threads[totalPhilosophers];
    Philosopher philosophers[totalPhilosophers];

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 3; j++) {

            sem_init(&tableForks[i][j], 0, 1);
        }
    }

    for (int i = 0; i < totalPhilosophers; i++) {

        philosophers[i].philosopherId = i;
        philosophers[i].tableId = i / 3;
        
        philosophers[i].forks = tableForks[philosophers[i].tableId];
        philosophers[i].totalSeats = 3;

        pthread_create(&threads[i], NULL, philosopherRoutine, &philosophers[i]);
    }

    for (int i = 0; i < totalPhilosophers; i++) {

        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 3; j++) {

            sem_destroy(&tableForks[i][j]);
        }
    }

    pthread_exit(0);
}
