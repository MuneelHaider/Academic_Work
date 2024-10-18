#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

#define MAX_STUDENTS_IN_ROOM 5
#define TOTAL_STUDENTS 20
#define NUM_GROUPS 5

sem_t roomSem;

pthread_mutex_t groupMutex[NUM_GROUPS];
pthread_mutex_t printMutex;

char *student_names[TOTAL_STUDENTS] = {

    "Ahmad", "Hasnat", "Humaid", "Ali", "Faziha",
    "Fatima", "Sawaira", "Maryam", "Waleed", "Saad",
    "Usman", "Taha", "Afnan", "Bisma", "Zainab",
    "Tamia", "Samiya", "Iqra", "Momina", "Minahil"
};

int groups[NUM_GROUPS][5] = {

    {0, 1, 2, 3 },
    {4, 5, 6, 7 },
    {8, 9, 10, 11 },
    {12, 13, 14, 15 },
    {16, 17, 18, 19 }
};

int get_student_group(int student_id) {

    for (int i = 0; i < NUM_GROUPS; i++) {

        for (int j = 0; j < 5; j++) {

            if (groups[i][j] == student_id) {

                return i;
            }
        }
    }

    return -1;
}

void print_message(const char* message) {

    pthread_mutex_lock(&printMutex);
    printf("%s\n", message);

    fflush(stdout);
    pthread_mutex_unlock(&printMutex);

    sleep(1);
}

void *student_demo(void *student_id) {

    int id = *((int *)student_id);
    int group = get_student_group(id);

    char message[100];
    sleep(id % 3 + 1);

    pthread_mutex_lock(&groupMutex[group]);
    sem_wait(&roomSem);

    sprintf(message, "%s from group %d has entered the room.", student_names[id], group + 1);
    print_message(message);
    sleep(2);

    sprintf(message, "%s from group %d has left the room.", student_names[id], group + 1);
    print_message(message);

    sem_post(&roomSem);
    pthread_mutex_unlock(&groupMutex[group]);
    sleep(2);

    free(student_id);
    return NULL;
}

int main() {

    pthread_t students[TOTAL_STUDENTS];

    sem_init(&roomSem, 0, MAX_STUDENTS_IN_ROOM);
    pthread_mutex_init(&printMutex, NULL);

    for (int i = 0; i < NUM_GROUPS; i++) {

        pthread_mutex_init(&groupMutex[i], NULL);
    }

    for (int i = 0; i < TOTAL_STUDENTS; i++) {

        int *id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&students[i], NULL, student_demo, (void *)id);
    }

    for (int i = 0; i < TOTAL_STUDENTS; i++) {

        pthread_join(students[i], NULL);
    }

    sem_destroy(&roomSem);
    pthread_mutex_destroy(&printMutex);

    for (int i = 0; i < NUM_GROUPS; i++) {

        pthread_mutex_destroy(&groupMutex[i]);
    }

    pthread_exit(0);
}