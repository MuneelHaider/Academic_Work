#pragma once
#include<iostream>
#include<queue>
using namespace std;

struct Graph {

	int vertex;
	int** adjacencyMatrix;

	Graph(int s) {

		vertex = s;
		adjacencyMatrix = new int* [s];

		for (int i = 0; i < s; i++) {

			adjacencyMatrix[i] = new int[s];

			for (int j = 0; j < s; j++) {

				adjacencyMatrix[i][j] = 0;
			}
		}
	}

	void addVertex() {

		vertex++;

		int** matrix = new int* [vertex];

		for (int i = 0; i < vertex; i++) {

			matrix[i] = new int[vertex];

			for (int j = 0; j < vertex; j++) {

				if (i < vertex-1 && j < vertex-1) {

					matrix[i][j] = adjacencyMatrix[i][j];
				}
				else {

					matrix[i][j] = 0;
				}
			}
		}
		adjacencyMatrix = matrix;
	}

	int getNumVertices() {

		return vertex;
	}

	int** getMatrix() {

		return adjacencyMatrix;
	}

	void addEdge(int from, int to, int weight) {

		if (to >= 0 && from >= 0 /*&& to < vertex && from < vertex*/) {

			adjacencyMatrix[from][to] = weight;
		}
	}

	void bfsTraversal(int index) {

		bool* visited = new bool[vertex];

		for (int i = 0; i < vertex; i++) {

			visited[i] = false;
		}

		queue<int> queue;
		visited[index] = true;
		queue.push(index);

		cout << "BFS Traversal: ";

		while (!queue.empty()) {

			int currentVertex = queue.front();
			queue.pop();
			cout << currentVertex << " ";

			for (int i = 0; i < vertex; i++) {

				if (adjacencyMatrix[currentVertex][i] != 0 && !visited[i]) {

					visited[i] = true;
					queue.push(i);
				}
			}
		}
		cout << endl;
	}


	void depthFirstSearch(int vertex, bool* visited) {

		visited[vertex] = true;
		cout << vertex << " ";

		for (int i = 0; i < vertex; i++) {
		
			if (adjacencyMatrix[vertex][i] != 0 && !visited[i]) {
			
				depthFirstSearch(i, visited);
			}
		}
	}

	void dfsTraversal(int start) {
		
		bool* visited = new bool[vertex];
		
		for (int i = 0; i < vertex; i++) {
		
			visited[i] = false;
		}
		
		cout << "DFS Traversal: ";
		
		depthFirstSearch(start, visited);
		delete[] visited;
		cout << endl;
	}
};