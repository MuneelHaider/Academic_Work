#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

const int ROOM_SIZE = 100;
const int NUM_ROBOTS = 50;
const int EXIT_WIDTH = 20;
const int MAX_ESTIMATION_RANGE = 10;
const int MAX_NEIGHBORS = 10;

float Total_width = 0;

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
    float neighborEstimates[MAX_NEIGHBORS];
    int numNeighbors;

    Robot() : position(0, 0), estimatedWidth(0), accuracy(0), numNeighbors(0) {}

    void estimateExitWidth(const Position& exitPosition) {
        float distanceToExit = sqrt(pow(position.x - exitPosition.x, 2) + pow(position.y - exitPosition.y, 2));
        if (distanceToExit <= 5) {
            accuracy = 0.95;
        } else if (distanceToExit <= 10) {
            accuracy = 0.88;
        } else {
            accuracy = 0.78;
        }
        estimatedWidth = EXIT_WIDTH * accuracy + (rand() % (2 * MAX_ESTIMATION_RANGE + 1) - MAX_ESTIMATION_RANGE);
        estimatedWidth = max(static_cast<float>(0), min(estimatedWidth, static_cast<float>(EXIT_WIDTH + MAX_ESTIMATION_RANGE)));
    }

    void receiveEstimateFrom(const Robot& other) {
        float distanceToOther = sqrt(pow(position.x - other.position.x, 2) + pow(position.y - other.position.y, 2));
        if (distanceToOther <= 5 && numNeighbors < MAX_NEIGHBORS) {
            neighborEstimates[numNeighbors++] = other.estimatedWidth;
        }
    }

    float computeAverageEstimate() {
        float sum = estimatedWidth;
        for (int i = 0; i < numNeighbors; ++i) {
            sum += neighborEstimates[i];
        }
        return numNeighbors > 0 ? sum / (numNeighbors + 1) : estimatedWidth;
    }
};

void initializeRobots(Robot robots[], int size, const Position& exitPosition) {
    for (int i = 0; i < size; ++i) {
        robots[i].position.x = rand() % ROOM_SIZE;
        robots[i].position.y = rand() % ROOM_SIZE;
        robots[i].estimateExitWidth(exitPosition);
    }
}

void communicateEstimates(Robot robots[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                robots[i].receiveEstimateFrom(robots[j]);
            }
        }
    }
}

int main() {
    srand(time(nullptr));
    Position exitPosition(50, 0);
    cout << "Exit is at position: (" << exitPosition.x << ", " << exitPosition.y << ")\n\n";
    Robot robots[NUM_ROBOTS];
    initializeRobots(robots, NUM_ROBOTS, exitPosition);
    communicateEstimates(robots, NUM_ROBOTS);
    float Total_width = 0;
    for (int i = 0; i < NUM_ROBOTS; ++i) {
        float averageEstimate = robots[i].computeAverageEstimate();
        Total_width += averageEstimate;
        cout << "Robot " << i + 1 << " at (" << robots[i].position.x << ", " << robots[i].position.y << ") ";
        cout << "estimated width: " << robots[i].estimatedWidth << ", ";
        cout << "accuracy: " << robots[i].accuracy * 100 << "%, ";
        cout << "average estimate: " << averageEstimate << endl;
    }
    this_thread::sleep_for(chrono::seconds(10));
    float averageWidth = Total_width / NUM_ROBOTS;
    cout << "\nOverall average estimated width: " << averageWidth << endl;
    cout << "True exit width: " << EXIT_WIDTH << endl;
    cout << "Difference: " << abs(averageWidth - EXIT_WIDTH) << endl;
    return 0;
}
