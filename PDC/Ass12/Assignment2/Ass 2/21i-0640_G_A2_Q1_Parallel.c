//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <stdbool.h>
//
///*  
//    Muneel Haider
//    i21-0640
//    PDC - Assingment 2
//    Question 1 - Parallel 
//*/
//
//typedef struct {
//
//    int size;
//    int** matrix;
//
//} CityMap;
//
//CityMap* createMap(int size) {
//
//    CityMap* citymap = (CityMap*)malloc(sizeof(CityMap));
//
//    citymap->size = size;
//    citymap->matrix = (int**)malloc(size * sizeof(int*));
//
//    for (int city1 = 0; city1 < size; city1++) {
//
//        citymap->matrix[city1] = (int*)malloc(size * sizeof(int));
//
//        for (int city2 = 0; city2 < size; city2++) {
//
//            citymap->matrix[city1][city2] = INT_MAX;
//        }
//    }
//
//    return citymap;
//}
//
//void AddEdgeCities(CityMap* citymap, int city1, int city2, int distance) {
//
//    if (city1 < citymap->size && city2 < citymap->size) {
//
//        citymap->matrix[city1][city2] = distance;
//        citymap->matrix[city2][city1] = distance;
//    }
//}
//
//void freeCityMap(CityMap* citymap) {
//
//    for (int city = 0; city < citymap->size; city++) {
//
//        free(citymap->matrix[city]);
//    }
//
//    free(citymap->matrix);
//    free(citymap);
//}
//
//void broadcastCity(CityMap* citymap, int rank) {
//
//    MPI_Bcast(&citymap->size, 1, MPI_INT, 0, MPI_COMM_WORLD);
//
//    if (rank != 0) {
//
//        citymap->matrix = (int**)malloc(citymap->size * sizeof(int*));
//
//        for (int city = 0; city < citymap->size; city++) {
//
//            citymap->matrix[city] = (int*)malloc(citymap->size * sizeof(int));
//        }
//    }
//
//    for (int city = 0; city < citymap->size; city++) {
//
//        MPI_Bcast(citymap->matrix[city], citymap->size, MPI_INT, 0, MPI_COMM_WORLD);
//    }
//}
//
//void DFS(CityMap* citymap, int currentCity, bool* visited, int distance, int* minDistance, int startCity) {
//
//    visited[currentCity] = true;
//    bool allVisited = true;
//
//    for (int city = 0; city < citymap->size; city++) {
//
//        if (!visited[city]) {
//
//            allVisited = false;
//
//            if (citymap->matrix[currentCity][city] != INT_MAX) {
//
//                DFS(citymap, city, visited, distance + citymap->matrix[currentCity][city], minDistance, startCity);
//            }
//        }
//    }
//    if (allVisited && citymap->matrix[currentCity][startCity] != INT_MAX) {
//
//        int totalDistance = distance + citymap->matrix[currentCity][startCity];
//
//        if (totalDistance < *minDistance) {
//
//            *minDistance = totalDistance;
//        }
//    }
//
//    visited[currentCity] = false;
//}
//
//int CalcShortestRoute(CityMap* citymap, int startCity) {
//
//    bool* visited = (bool*)calloc(citymap->size, sizeof(bool));
//    int minDistance = INT_MAX;
//
//    DFS(citymap, startCity, visited, 0, &minDistance, startCity);
//
//    free(visited);
//
//    return minDistance;
//}
//
//int main(int argc, char* argv[]) {
//
//    MPI_Init(&argc, &argv);
//
//    double startTime = MPI_Wtime();
//
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    CityMap* citymap = createMap(5);
//
//    AddEdgeCities(citymap, 0, 1, 20);
//    AddEdgeCities(citymap, 0, 2, 30);
//    AddEdgeCities(citymap, 0, 3, 40);
//    AddEdgeCities(citymap, 0, 4, 25);
//    AddEdgeCities(citymap, 1, 2, 35);
//    AddEdgeCities(citymap, 1, 3, 10);
//    AddEdgeCities(citymap, 1, 4, 45);
//    AddEdgeCities(citymap, 2, 3, 55);
//    AddEdgeCities(citymap, 2, 4, 15);
//    AddEdgeCities(citymap, 3, 4, 50);
//
//    broadcastCity(citymap, rank);
//
//    int localMinDistance = INT_MAX;
//
//    if (rank < citymap->size) {
//
//        localMinDistance = CalcShortestRoute(citymap, rank);
//    }
//
//    int globalMinDistance;
//
//    MPI_Reduce(&localMinDistance, &globalMinDistance, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
//
//    double endTime = MPI_Wtime();
//
//    if (rank == 0) {
//
//        printf("Minimum route distance: %d\n", globalMinDistance);
//        printf("Total execution time: %f seconds\n", endTime - startTime);
//    }
//
//    freeCityMap(citymap);
//
//    MPI_Finalize();
//    return 0;
//}
