#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>
#include <semaphore.h>
using namespace std;

/*
    Muneel Haider       i210640
    Muhammad Abudullah  i210643

    OS Project 2023
*/

float widthTotal = 0;
mutex mutex1;
mutex mutex2;
sem_t sem;

class Position {

public:

    int x, y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

};

class Robot {

public:
    
    Position position;
    
    float estimatedWidth;
    float accuracy;
    float neighborEstimates[10];
    int numNeighbors;

    Robot() : position(0, 0), estimatedWidth(0), accuracy(0), numNeighbors(0) {}

    void estimateExitWidth(const Position &exitPosition) {

        // Using the (x^2) + (y^2) Formula
        float distanceToExit = sqrt(pow(position.x - exitPosition.x, 2) + pow(position.y - exitPosition.y, 2));
        
        int trueWidth = 20;

        if (distanceToExit <= 5) {

            accuracy = 0.95;
        }
        else if (distanceToExit <= 10) {

            accuracy = 0.88;
        }
        else if (distanceToExit <= 15) {

            accuracy = 0.78;
        }
        else {

            accuracy = 0.69;
        }

        float randomFactor = static_cast<float>(rand() % 20) - 10;
        
        estimatedWidth = trueWidth * accuracy + randomFactor * accuracy;
        
        estimatedWidth = max(min(estimatedWidth, trueWidth + 10.0f), 0.0f);
    }

    void receiveEstimateFrom(const Robot &other) {

        // Using the same x^2 - y^2 Formula
        float distanceToOther = sqrt(pow(position.x - other.position.x, 2) + pow(position.y - other.position.y, 2));
        
        if (distanceToOther <= 5 && numNeighbors < 10) {

            neighborEstimates[numNeighbors++] = other.estimatedWidth;
        }
    }

    float computeAverageEstimate() {

        float sum = estimatedWidth;
        
        for (int i = 0; i < numNeighbors; i++) {

            sum += neighborEstimates[i];
        }

        return numNeighbors > 0 ? sum / (numNeighbors + 1) : estimatedWidth;
    }
};

void robotFunction(Robot &robot, const Position &exitPosition, Robot robots[], int index, sem_t *sem) {

    mutex2.lock();

    robot.position.x = rand() % 100;
    robot.position.y = rand() % 100;
    
    robot.estimateExitWidth(exitPosition);

    for (int j = 0; j < 50; j++) {

        if (index != j)
        {
            // Using semaphores
            sem_wait(sem);
            robot.receiveEstimateFrom(robots[j]);
            sem_post(sem);
        }
    }

    float averageEstimate = robot.computeAverageEstimate();

    widthTotal += averageEstimate;

    cout << "Robot " << index + 1 << " at (" << robot.position.x << ", " << robot.position.y << ") ";
    cout << "estimated width: " << robot.estimatedWidth << ", ";
    cout << "accuracy: " << robot.accuracy * 100 << "%, ";
    cout << "average estimate: " << averageEstimate << endl;

    mutex2.unlock();
}

int main()
{
    srand(time(nullptr));

    Position exitPosition(50, 50);
    cout << "Exit is at position: (" << exitPosition.x << ", " << exitPosition.y << ")\n\n";

    thread robotThreads[50];
    Robot robots[50];
    sem_init(&sem, 0, 1);

    for (int i = 0; i < 50; i++) {

        robotThreads[i] = thread(robotFunction, ref(robots[i]), ref(exitPosition), robots, i, &sem);
    }

    for (int i = 0; i < 50; i++) {

        robotThreads[i].join();
    }

    this_thread::sleep_for(chrono::seconds(10));

    float averageWidth = widthTotal / 50;
    
    cout << endl << "Overall average estimated width: " << averageWidth << endl;
    cout << "True exit width: 20" << endl;
    cout << "Difference: " << abs(averageWidth - 20) << endl;

    sem_destroy(&sem);

    pthread_exit(0);
}