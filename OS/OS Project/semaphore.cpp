#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <math.h>
#include <cstring>
#include <time.h>

#define NUM_ROBOTS 50
#define ROOM_SIZE 100
#define EXIT_WIDTH 20
#define MAX_DISTANCE 10
#define MAX_ROBOTS_IN_RANGE 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int id;
    Position position;
    float estimated_width;
    float estimates[MAX_ROBOTS_IN_RANGE];
    int num_estimates;
} Robot;

typedef struct {
    float total_width;
    sem_t mutex;
} SharedData;

float distance(Position p1, Position p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float calculate_accuracy(int distance) {
    float accuracy = 1.0 - (float)distance / (ROOM_SIZE * sqrt(2));
    return accuracy > 0 ? accuracy : 0; // Ensure accuracy is not negative
}

Position random_position() {
    Position pos;
    pos.x = rand() % ROOM_SIZE;
    pos.y = rand() % ROOM_SIZE;
    return pos;
}

float estimate_width(Position robot_position) {
    int dist_to_exit = distance(robot_position, (Position){ROOM_SIZE, ROOM_SIZE});
    float accuracy = calculate_accuracy(dist_to_exit);
    float estimatedWidth = EXIT_WIDTH * accuracy;
    return estimatedWidth > 0 ? estimatedWidth : 0; // Ensure estimated width is not negative
}

void collect_estimates(Robot *robot, Robot *all_robots, Position exit_position) {
    memset(robot->estimates, 0, sizeof(robot->estimates));
    robot->num_estimates = 0;
    float dist_to_exit = distance(robot->position, exit_position);

    for (int i = 0; i < NUM_ROBOTS; i++) {
        if (all_robots[i].id != robot->id) {
            float dist_to_other = distance(robot->position, all_robots[i].position);
            if (dist_to_other <= MAX_DISTANCE && dist_to_exit > dist_to_other) {
                robot->estimates[robot->num_estimates++] = all_robots[i].estimated_width;
            }
        }
    }
    robot->estimates[robot->num_estimates++] = robot->estimated_width;
}

void* robot_routine(void* arg) {
    Robot* robot = (Robot*)arg;
    SharedData* shared_data = (SharedData*)(robot + NUM_ROBOTS);
    
    printf("Robot %d routine started. Position: (%d, %d)\n", robot->id, robot->position.x, robot->position.y);

    robot->estimated_width = estimate_width(robot->position);
    printf("Robot %d estimated width: %f\n", robot->id, robot->estimated_width);

    collect_estimates(robot, (Robot*)arg, (Position){ROOM_SIZE, ROOM_SIZE});

    sem_wait(&shared_data->mutex);
    float average_estimate = robot->estimated_width;
    for (int i = 0; i < robot->num_estimates; i++) {
        average_estimate += robot->estimates[i];
    }
    average_estimate /= (robot->num_estimates > 0) ? robot->num_estimates : 1;
    shared_data->total_width += average_estimate;
    sem_post(&shared_data->mutex);

    printf("Robot %d routine finished. Average estimate: %f\n", robot->id, average_estimate);

    return NULL;
}


int main() {
    srand(time(NULL));  // Initialize random number generator
    int i;
    pid_t pids[NUM_ROBOTS];

    int shm_id = shmget(IPC_PRIVATE, sizeof(Robot) * NUM_ROBOTS + sizeof(SharedData), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    Robot* all_robots = (Robot*)shmat(shm_id, NULL, 0);
    if (all_robots == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    SharedData* shared_data = (SharedData*)(all_robots + NUM_ROBOTS);
    sem_init(&shared_data->mutex, 1, 1);
    shared_data->total_width = 0;

    for (i = 0; i < NUM_ROBOTS; i++) {
        all_robots[i].id = i;
        all_robots[i].position = random_position();
        all_robots[i].estimated_width = estimate_width(all_robots[i].position);
    }

    for (i = 0; i < NUM_ROBOTS; i++) {
        pids[i] = fork();
        if (pids[i] == 0) { // Child process
            printf("Child process %d started.\n", i);
            pthread_t thread;
            if (pthread_create(&thread, NULL, robot_routine, (void*)&all_robots[i]) != 0) {
                perror("pthread_create");
                exit(1);
            }
            if (pthread_join(thread, NULL) != 0) {
                perror("pthread_join");
                exit(1);
            }
            printf("Child process %d finished.\n", i);
            exit(0);
        } else if (pids[i] < 0) {
            perror("fork");
            exit(1);
        }
    }

    for (i = 0; i < NUM_ROBOTS; i++) {
        if (wait(NULL) < 0) {
            perror("wait");
        }
    }

    printf("Average estimated width: %f\n", shared_data->total_width / NUM_ROBOTS);

    if (sem_destroy(&shared_data->mutex) != 0) {
        perror("sem_destroy");
    }
    if (shmdt(shared_data) != 0) {
        perror("shmdt");
    }
    if (shmctl(shm_id, IPC_RMID, NULL) != 0) {
        perror("shmctl");
    }
    return 0;
}
