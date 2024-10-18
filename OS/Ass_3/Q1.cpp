#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*

    Muneel Haider
    21i-0640
    Assignment 3
    Question 1

*/

typedef struct {

    int id;
    int skill;
    int availability;

} TeamMember;

typedef struct {

    int id;
    int requiredSkill;
    int priority;
    int deadline;
    int completed;

} Task;

TeamMember teamMembers[6];
Task tasks[15];
pthread_mutex_t mutex;

int findNextTaskForMember(int memberId) {

    int highestPriority = 50;
    int earliestDeadline = 50;
    int nextTask = -1;

    for (int i = 0; i < 15; i++) {

        if (!tasks[i].completed && tasks[i].requiredSkill == teamMembers[memberId].skill && tasks[i].priority < highestPriority && tasks[i].deadline < earliestDeadline) {

            highestPriority = tasks[i].priority;
            earliestDeadline = tasks[i].deadline;
            
            nextTask = i;
        }
    }
    
    return nextTask;
}

void* performTasks(void* arg) {

    int tasksCompleted = 0;
    
    while (tasksCompleted < 15) {

        for (int i = 0; i < 6; i++) {

            pthread_mutex_lock(&mutex);

            int taskIndex = findNextTaskForMember(i);

            if (taskIndex != -1) {

                Task* task = &tasks[taskIndex];
                task->completed = 1;

                pthread_mutex_unlock(&mutex);

                printf("Team member %d starts task %d\n", teamMembers[i].id, task->id);
                sleep(1);
               
                printf("Team member %d finished task %d\n", teamMembers[i].id, task->id);
                sleep(2);

                tasksCompleted++;

            } else {

                pthread_mutex_unlock(&mutex);
            }
        }
    }
    
    return NULL;
}

int main() {

    teamMembers[0] = (TeamMember){1, 0, 1};
    teamMembers[1] = (TeamMember){2, 0, 1};
    teamMembers[2] = (TeamMember){3, 1, 1};
    teamMembers[3] = (TeamMember){4, 1, 1};
    teamMembers[4] = (TeamMember){5, 2, 1};
    teamMembers[5] = (TeamMember){6, 2, 1};

    tasks[0] = (Task){1, 0, 1, 10, 0};
    tasks[1] = (Task){2, 0, 2, 9, 0};
    tasks[2] = (Task){3, 0, 3, 8, 0};
    tasks[3] = (Task){4, 1, 2, 7, 0};
    tasks[4] = (Task){5, 1, 1, 6, 0};
    tasks[5] = (Task){6, 1, 3, 5, 0};
    tasks[6] = (Task){7, 2, 1, 4, 0};
    tasks[7] = (Task){8, 2, 2, 3, 0};
    tasks[8] = (Task){9, 2, 3, 2, 0};
    tasks[9] = (Task){10, 0, 2, 1, 0};
    tasks[10] = (Task){11, 0, 1, 2, 0};
    tasks[11] = (Task){12, 1, 1, 3, 0};
    tasks[12] = (Task){13, 1, 2, 4, 0};
    tasks[13] = (Task){14, 2, 3, 5, 0};
    tasks[14] = (Task){15, 2, 2, 6, 0};

    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread, NULL, performTasks, NULL);
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);

    pthread_exit(0);
}