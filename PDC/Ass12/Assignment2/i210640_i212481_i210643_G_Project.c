#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <mpi.h>
#include <omp.h>
#include <time.h>

//    Muneel Haider       i210640
//    Muhammad Abdullah   i210643
//    Abdullah Zahoor     i212481
//    PDC Project

typedef struct {

    int node;
    int cost;
} Queue;

void insertQueue(Queue* pq, int* pqSize, Queue newElement) {

    pq[(*pqSize)++] = newElement;
    for (int i = *pqSize - 1; i > 0 && pq[i].cost < pq[i - 1].cost; --i) {
    
        Queue temp = pq[i];
        pq[i] = pq[i - 1];
        pq[i - 1] = temp;
    }
}

void findKShortest(int edges[][3], int n, int m, int k, int source, int destination, int* localResult) {

    Queue** q = (Queue**)malloc((n + 1) * sizeof(Queue*));
    
    for (int i = 0; i <= n; ++i) {
        q[i] = NULL;
    }
    int* qSize = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; ++i) {
    
        Queue* newQueue = (Queue*)realloc(q[edges[i][0]], (qSize[edges[i][0]] + 1) * sizeof(Queue));
        q[edges[i][0]] = newQueue;
        q[edges[i][0]][qSize[edges[i][0]]].node = edges[i][1];
        q[edges[i][0]][qSize[edges[i][0]]].cost = edges[i][2];
        qSize[edges[i][0]]++;
    }

    int** arrayDistance = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; ++i) {
       
        arrayDistance[i] = (int*)malloc(k * sizeof(int));
        for (int j = 0; j < k; ++j) {
    
            arrayDistance[i][j] = INT_MAX;
        }
    }
    arrayDistance[source][0] = 0;

    Queue* pq = (Queue*)malloc((n * k) * sizeof(Queue));
    int pqSize = 0;
    insertQueue(pq, &pqSize, (Queue) { source, 0 });

    while (pqSize > 0) {
        
        Queue top = pq[0];
        memmove(pq, pq + 1, (pqSize - 1) * sizeof(Queue));
        pqSize--;
   
        int a = top.node;
        int b = top.cost;

        if (arrayDistance[a][k - 1] < b) {
            continue;
        }

        int i = 0;
        #pragma omp parallel for private(i)
        for (i = 0; i < qSize[a]; ++i) {
            int dest = q[a][i].node;
            int cost = q[a][i].cost;
            #pragma omp critical
            {
                if (b + cost < arrayDistance[dest][k - 1]) {
                    arrayDistance[dest][k - 1] = b + cost;
                    for (int j = k - 1; j > 0 && arrayDistance[dest][j] < arrayDistance[dest][j - 1]; --j) {
                        int temp = arrayDistance[dest][j];
                        arrayDistance[dest][j] = arrayDistance[dest][j - 1];
                        arrayDistance[dest][j - 1] = temp;
                    }
                    insertQueue(pq, &pqSize, (Queue) { dest, b + cost });
                }
            }
        }
    }

    memcpy(localResult, arrayDistance[destination], k * sizeof(int));

    for (int i = 0; i <= n; ++i) {
        free(q[i]);
        free(arrayDistance[i]);
    }
    free(q);
    free(qSize);
    free(arrayDistance);
    free(pq);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 0, M = 0, K = 10;
    int(*edges)[3] = NULL;

    if (rank == 0) {
        
        FILE* file = fopen("2.txt", "r");
        if (file == NULL) {
            perror("Error opening file");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        fscanf_s(file, "# Nodes: %d Edges: %d", &N, &M);

        edges = (int(*)[3])malloc(M * sizeof(*edges));
        if (edges == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        srand((unsigned int)time(NULL));
        int index = 0, u, v;
        char line[128];

        while (fgets(line, sizeof(line), file)) {
        
            if (line[0] == '#') {
                continue;
            }
            
            if (sscanf_s(line, "%d %d", &u, &v) == 2) {
                edges[index][0] = u;
                edges[index][1] = v;
                edges[index][2] = rand() % 20 + 1;
                index++;
            }
        }
        fclose(file);
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if (rank != 0) {
        edges = (int(*)[3])malloc(M * sizeof(*edges));
    }
    
    MPI_Bcast(edges, M * 3, MPI_INT, 0, MPI_COMM_WORLD);

    int pairs[10][2];
    
    if (rank == 0) {
        for (int i = 0; i < 10; i++) {
    
            pairs[i][0] = rand() % N + 1;
            pairs[i][1] = rand() % N + 1;
        }
    }
    MPI_Bcast(pairs, 10 * 2, MPI_INT, 0, MPI_COMM_WORLD);

    int* localResult = (int*)malloc(K * sizeof(int));
    
    if (localResult == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    int* results = NULL;
    
    if (rank == 0) {
        results = (int*)malloc(10 * K * sizeof(int));
    
        if (results == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
        }
    }

    int validPairs[10][2];
    int validPairCount = 0;

    for (int i = 0; i < 10; i++) {
        int src = pairs[i][0];
        int dest = pairs[i][1];
        int validSrc = 0, validDest = 0;
        
        for (int j = 0; j < M; j++) {
            if (edges[j][0] == src) validSrc = 1;
            if (edges[j][1] == dest) validDest = 1;
            if (validSrc && validDest) break;
        }
        
        if (validSrc && validDest) {
            validPairs[validPairCount][0] = src;
            validPairs[validPairCount][1] = dest;
            validPairCount++;
        }
    }

    for (int i = 0; i < validPairCount; i++) {

        findKShortest(edges, N, M, K, validPairs[i][0], validPairs[i][1], localResult);
        MPI_Gather(localResult, K, MPI_INT, results, K, MPI_INT, 0, MPI_COMM_WORLD);
        
        if (rank == 0) {
        
            int hasValidPath = 0;
            for (int j = 0; j < K; j++) {
            
                if (results[i * K + j] != INT_MAX && results[i * K + j] != -842150451) {
                    hasValidPath = 1;
                    break;
                }
            }
            if (!hasValidPath) {
               
                findKShortest(edges, N, M, K, validPairs[i][0], validPairs[i][1], localResult);
                printf("Top %d shortest paths from %d to %d:\n", K, validPairs[i][0], validPairs[i][1]);
                
                for (int j = 0; j < K; j++) {
                    if (localResult[j] != INT_MAX) {
                        printf("%d ", localResult[j]);
                    }
                    else {
                        printf("No path found.");
                        break;
                    }
                }
                printf("\n\n");
            }
            else {
                printf("Top %d shortest paths from %d to %d:\n", K, validPairs[i][0], validPairs[i][1]);
                for (int j = 0; j < K; j++) {
                    if (results[i * K + j] != INT_MAX && results[i * K + j] != -842150451) {
                        printf("%d ", results[i * K + j]);
                    }
                    else {
                        printf("No path found.");
                        break;
                    }
                }
                printf("\n\n");
            }
        }
    }

    if (rank == 0) {
        free(results);
    }
    free(edges);
    free(localResult);

    MPI_Finalize();
    return 0;
}
