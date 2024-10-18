#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
    Muneel Haider       21i-0640
    Muhammad Abdullah   21i-0643
    Abdullah Zahoor     21i-2481
    Algo Project - CS 23
*/

const int maximumVertices = 1000;
const int IntMAX = 1000000;

class Queue
{

public:

    int items[maximumVertices * 2];
    int front, rear;

    Queue() : front(0), rear(-1) {}

    bool isEmpty()
    {
        return front > rear;
    }

    void enqueue(int item)
    {
        if (rear < maximumVertices * 2 - 1)
        {
            items[++rear] = item;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            return items[front++];
        }

        return -1;
    }
};

int shortestCycleBFS(int start, int n, bool graph[maximumVertices][maximumVertices])
{
    Queue q;
    
    bool visited[maximumVertices] = {false};
    int level[maximumVertices] = {0};
    int parent[maximumVertices];
    
    fill_n(parent, maximumVertices, -1);

    q.enqueue(start);
    
    visited[start] = true;

    while (!q.isEmpty())
    {
        int vertex = q.dequeue();

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    level[i] = level[vertex] + 1;
                    parent[i] = vertex;
    
                    q.enqueue(i);
                }
                else if (parent[vertex] != i)
                {
                    return level[vertex] + level[i] + 1;
                }
            }
        }
    }
    
    return -1; 
}

int shortestCycleLength(int n, bool graph[maximumVertices][maximumVertices])
{
    int minCycle = IntMAX;

    for (int i = 0; i < n; i++)
    {
        int cycle = shortestCycleBFS(i, n, graph);
    
        if (cycle != -1 && cycle < minCycle)
        {
            minCycle = cycle;
        }
    }
    
    return minCycle == IntMAX ? -1 : minCycle;
}

int main()
{
    string filename = "testcase1.txt";
    
    ifstream file(filename);
    
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return -1;
    }

    int n, u, v;
    
    file >> n;
    
    bool graph[maximumVertices][maximumVertices] = {false};

    while (file >> u >> v)
    {
        graph[u][v] = graph[v][u] = true;
    
        cout << "Vertex " << u << " is connected to Vertex " << v << endl;
    }

    file.close();
    
    cout << endl << "Shortest Cycle Length: " << shortestCycleLength(n, graph) << endl << endl;

    return 0;
}
