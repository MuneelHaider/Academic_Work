//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <stdbool.h>
//
//typedef struct {
//    int size;
//    int** matrix;
//} Graph;
//
//Graph* createGraph(int size) {
//    Graph* graph = (Graph*)malloc(sizeof(Graph));
//    graph->size = size;
//    graph->matrix = (int**)malloc(size * sizeof(int*));
//    for (int i = 0; i < size; i++) {
//        graph->matrix[i] = (int*)malloc(size * sizeof(int));
//        for (int j = 0; j < size; j++) {
//            graph->matrix[i][j] = INT_MAX;
//        }
//    }
//    return graph;
//}
//
//void addEdge(Graph* graph, int v1, int v2, int weight) {
//    if (v1 < graph->size && v2 < graph->size) {
//        graph->matrix[v1][v2] = weight;
//        graph->matrix[v2][v1] = weight;
//    }
//}
//
//void freeGraph(Graph* graph) {
//    for (int i = 0; i < graph->size; i++) {
//        free(graph->matrix[i]);
//    }
//    free(graph->matrix);
//    free(graph);
//}
//
//void broadcastGraph(Graph* graph, int world_rank) {
//    MPI_Bcast(&graph->size, 1, MPI_INT, 0, MPI_COMM_WORLD);
//    if (world_rank != 0) {
//        graph->matrix = (int**)malloc(graph->size * sizeof(int*));
//        for (int i = 0; i < graph->size; i++) {
//            graph->matrix[i] = (int*)malloc(graph->size * sizeof(int));
//        }
//    }
//    for (int i = 0; i < graph->size; i++) {
//        MPI_Bcast(graph->matrix[i], graph->size, MPI_INT, 0, MPI_COMM_WORLD);
//    }
//}
//
//void DFS(Graph* graph, int currentCity, bool* visited, int pathLength, int* minPath, int startCity) {
//    visited[currentCity] = true;
//    bool allVisited = true;
//    for (int i = 0; i < graph->size; i++) {
//        if (!visited[i]) {
//            allVisited = false;
//            if (graph->matrix[currentCity][i] != INT_MAX) {
//                DFS(graph, i, visited, pathLength + graph->matrix[currentCity][i], minPath, startCity);
//            }
//        }
//    }
//    if (allVisited && graph->matrix[currentCity][startCity] != INT_MAX) {
//        int totalPathLength = pathLength + graph->matrix[currentCity][startCity];
//        if (totalPathLength < *minPath) {
//            *minPath = totalPathLength;
//        }
//    }
//    visited[currentCity] = false;
//}
//
//int calculateRouteDistance(Graph* graph, int startCity) {
//    bool* visited = (bool*)calloc(graph->size, sizeof(bool));
//    int minPath = INT_MAX;
//    DFS(graph, startCity, visited, 0, &minPath, startCity);
//    free(visited);
//    return minPath;
//}
//
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//
//    int world_rank, world_size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    Graph* graph = NULL;
//    if (world_rank == 0) {
//        graph = createGraph(4);
//        addEdge(graph, 0, 1, 10);
//        addEdge(graph, 0, 2, 15);
//        addEdge(graph, 1, 2, 20);
//        addEdge(graph, 1, 3, 30);
//        addEdge(graph, 2, 3, 35);
//        addEdge(graph, 0, 3, 40);
//    }
//    else {
//        graph = (Graph*)malloc(sizeof(Graph));
//    }
//
//    broadcastGraph(graph, world_rank);
//
//    int localMinPath = INT_MAX;
//    if (world_rank < graph->size) {
//        localMinPath = calculateRouteDistance(graph, world_rank);
//    }
//
//    int globalMinPath;
//    MPI_Reduce(&localMinPath, &globalMinPath, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
//
//    if (world_rank == 0) {
//        printf("Minimum route distance: %d\n", globalMinPath);
//    }
//
//    freeGraph(graph);
//    MPI_Finalize();
//    return 0;
//}
