#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

float Total_width = 0;
mutex Total_width_mutex;
mutex output_mutex; // Mutex for controlling output to prevent overlapping

class Position
{
public:
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class Robot
{
public:
    Position position;
    float estimatedWidth;
    float accuracy;
    float neighborEstimates[10];
    int numNeighbors;

    Robot() : position(0, 0), estimatedWidth(0), accuracy(0), numNeighbors(0) {}

    void estimateExitWidth(const Position &exitPosition)
    {
        float distanceToExit = sqrt(pow(position.x - exitPosition.x, 2) + pow(position.y - exitPosition.y, 2));
        if (distanceToExit <= 5)
        {
            accuracy = 0.95;
        }
        else if (distanceToExit <= 10)
        {
            accuracy = 0.88;
        }
        else if (distanceToExit <= 15)
        {
            accuracy = 0.78;
        }
        else
        {
            accuracy = 0.69;
        }

        estimatedWidth = 20 * accuracy + (rand() % (2 * 10 + 1) - 10);
        estimatedWidth = max(static_cast<float>(0), min(estimatedWidth, static_cast<float>(30)));
    }

    void receiveEstimateFrom(const Robot &other)
    {
        float distanceToOther = sqrt(pow(position.x - other.position.x, 2) + pow(position.y - other.position.y, 2));
        if (distanceToOther <= 5 && numNeighbors < 10)
        {
            neighborEstimates[numNeighbors++] = other.estimatedWidth;
        }
    }

    float computeAverageEstimate()
    {
        float sum = estimatedWidth;
        for (int i = 0; i < numNeighbors; ++i)
        {
            sum += neighborEstimates[i];
        }
        return numNeighbors > 0 ? sum / (numNeighbors + 1) : estimatedWidth;
    }
};

void robotFunction(Robot &robot, const Position &exitPosition, Robot robots[], int index)
{
    robot.position.x = rand() % 100;
    robot.position.y = rand() % 100;
    robot.estimateExitWidth(exitPosition);

    for (int j = 0; j < 50; ++j)
    {
        if (index != j)
        {
            robot.receiveEstimateFrom(robots[j]);
        }
    }

    float averageEstimate = robot.computeAverageEstimate();

    {
        lock_guard<mutex> lock(Total_width_mutex);
        Total_width += averageEstimate;
    }

    // Output is controlled by a separate mutex to prevent overlapping
    {
        lock_guard<mutex> output_lock(output_mutex);
        cout << "Robot " << index + 1 << " at (" << robot.position.x << ", " << robot.position.y << ") ";
        cout << "estimated width: " << robot.estimatedWidth << ", ";
        cout << "accuracy: " << robot.accuracy * 100 << "%, ";
        cout << "average estimate: " << averageEstimate << endl;
    }
}

int main()
{
    srand(time(nullptr));
    Position exitPosition(50, 50);
    cout << "Exit is at position: (" << exitPosition.x << ", " << exitPosition.y << ")\n\n";

    thread robotThreads[50];
    Robot robots[50];

    for (int i = 0; i < 50; ++i)
    {
        robotThreads[i] = thread(robotFunction, ref(robots[i]), exitPosition, robots, i);
    }

    for (int i = 0; i < 50; ++i)
    {
        robotThreads[i].join();
    }

    this_thread::sleep_for(chrono::seconds(10));

    float averageWidth = Total_width / 50;
    cout << "\nOverall average estimated width: " << averageWidth << endl;
    cout << "True exit width: 20" << endl;
    cout << "Difference: " << abs(averageWidth - 20) << endl;

    return 0;
}
