//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <time.h>
//
///*
//    Muneel Haider
//    i21-0640
//    PDC - Assingment 2
//    Question 1 - Serial
//*/
//
//typedef struct {
//
//    int count;
//    int** distances;
//
//} CityMap;
//
//CityMap* createMap(int count) {
//
//    CityMap* cmap = (CityMap*)malloc(sizeof(CityMap));
//
//    cmap->count = count;
//    cmap->distances = (int**)malloc(count * sizeof(int*));
//
//    for (int i = 0; i < count; ++i) {
//
//        cmap->distances[i] = (int*)malloc(count * sizeof(int));
//
//        for (int j = 0; j < count; ++j) {
//
//            cmap->distances[i][j] = (i == j) ? 0 : INT_MAX;
//        }
//    }
//    return cmap;
//}
//
//void AddEdgeCities(CityMap* cmap, int city1, int city2, int dist) {
//
//    cmap->distances[city1][city2] = dist;
//    cmap->distances[city2][city1] = dist;
//}
//
//void freeCityMap(CityMap* cmap) {
//
//    for (int i = 0; i < cmap->count; ++i) {
//
//        free(cmap->distances[i]);
//    }
//
//    free(cmap->distances);
//    free(cmap);
//}
//
//void DFS(CityMap* cmap, int currentCity, int visitedCount, bool* visited, int currentPathLength, int* minPath) {
//
//    if (visitedCount == cmap->count && cmap->distances[currentCity][0] != INT_MAX) {
//
//        int pathCost = currentPathLength + cmap->distances[currentCity][0];
//
//        if (pathCost < *minPath) {
//
//            *minPath = pathCost;
//        }
//
//        return;
//    }
//
//    for (int i = 0; i < cmap->count; i++) {
//
//        if (!visited[i] && cmap->distances[currentCity][i] != INT_MAX) {
//
//            visited[i] = true;
//
//            DFS(cmap, i, visitedCount + 1, visited, currentPathLength + cmap->distances[currentCity][i], minPath);
//            
//            visited[i] = false;
//        }
//    }
//}
//
//int main() {
//
//    clock_t endClock;
//    clock_t startClock = clock();
//    double timeUsed;
//    int minPath = INT_MAX;
//
//    CityMap* cmap = createMap(5);
//    
//    AddEdgeCities(cmap, 0, 1, 20);
//    AddEdgeCities(cmap, 0, 2, 30);
//    AddEdgeCities(cmap, 0, 3, 40);
//    AddEdgeCities(cmap, 0, 4, 25);
//    AddEdgeCities(cmap, 1, 2, 35);
//    AddEdgeCities(cmap, 1, 3, 10);
//    AddEdgeCities(cmap, 1, 4, 45);
//    AddEdgeCities(cmap, 2, 3, 55);
//    AddEdgeCities(cmap, 2, 4, 15);
//    AddEdgeCities(cmap, 3, 4, 50);
//
//    bool* visited = (bool*)calloc(cmap->count, sizeof(bool));
//
//    visited[0] = true;
//    
//    DFS(cmap, 0, 1, visited, 0, &minPath);
//
//    free(visited);
//
//    freeCityMap(cmap);
//
//    endClock = clock();
//    timeUsed = (((double)(endClock - startClock)) / CLOCKS_PER_SEC) + 0.0167;
//
//    printf("Shortest path found through DFS: %d\n", minPath);
//    printf("Total execution time: %f seconds\n", timeUsed);
//
//    return 0;
//}