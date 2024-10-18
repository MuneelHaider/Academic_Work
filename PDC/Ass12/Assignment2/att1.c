//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//
//typedef struct {
//    int node;
//    int cost;
//} Pair;
//
//void findKShortest(int edges[][3], int n, int m, int k) {
//    Pair** g = (Pair**)malloc((n + 1) * sizeof(Pair*));
//    if (!g) {
//        perror("Failed to allocate memory for graph");
//        return;
//    }
//
//    for (int i = 0; i <= n; ++i) {
//        g[i] = NULL;
//    }
//
//    int* gSize = (int*)calloc(n + 1, sizeof(int));
//    if (!gSize) {
//        perror("Failed to allocate memory for graph size array");
//        free(g);
//        return;
//    }
//
//    // Initialize graph
//    for (int i = 0; i < m; ++i) {
//        int u = edges[i][0];
//        Pair* newAlloc = (Pair*)realloc(g[u], (gSize[u] + 1) * sizeof(Pair));
//        if (!newAlloc) {
//            perror("Failed to reallocate memory for graph edges");
//            free(gSize);
//            for (int j = 0; j <= i; ++j) {
//                free(g[j]);
//            }
//            free(g);
//            return;
//        }
//        g[u] = newAlloc;
//        g[u][gSize[u]].node = edges[i][1];
//        g[u][gSize[u]].cost = edges[i][2];
//        gSize[u]++;
//    }
//
//    // Allocate distance array
//    int** dis = (int**)malloc((n + 1) * sizeof(int*));
//    if (!dis) {
//        perror("Failed to allocate memory for distances");
//        free(gSize);
//        for (int i = 0; i <= n; ++i) {
//            free(g[i]);
//        }
//        free(g);
//        return;
//    }
//
//    for (int i = 0; i <= n; ++i) {
//        dis[i] = (int*)malloc(k * sizeof(int));
//        if (!dis[i]) {
//            perror("Failed to allocate memory for distances array");
//            for (int j = 0; j < i; ++j) {
//                free(dis[j]);
//            }
//            free(dis);
//            free(gSize);
//            for (int j = 0; j <= n; ++j) {
//                free(g[j]);
//            }
//            free(g);
//            return;
//        }
//        for (int j = 0; j < k; ++j) {
//            dis[i][j] = INT_MAX;
//        }
//    }
//    dis[1][0] = 0;
//
//    // Priority queue functionality will be handled by a simple array
//    Pair* pq = (Pair*)malloc((n * k) * sizeof(Pair));
//    if (!pq) {
//        perror("Failed to allocate memory for priority queue");
//        for (int i = 0; i <= n; ++i) {
//            free(dis[i]);
//        }
//        free(dis);
//        free(gSize);
//        for (int i = 0; i <= n; ++i) {
//            free(g[i]);
//        }
//        free(g);
//        return;
//    }
//
//    int pqSize = 0;  // Priority queue size
//    pq[pqSize++] = (Pair){ 1, 0 };  // Start with source node
//
//    // Process the queue
//    while (pqSize > 0) {
//        Pair top = pq[0];  // Get the top element
//        // Remove the top element from the queue
//        memmove(pq, pq + 1, (pqSize - 1) * sizeof(Pair));
//        pqSize--;
//
//        int u = top.node;
//        int d = top.cost;
//        if (dis[u][k - 1] < d)
//            continue;
//
//        for (int i = 0; i < gSize[u]; ++i) {
//            int dest = g[u][i].node;
//            int cost = g[u][i].cost;
//
//            if (d + cost < dis[dest][k - 1]) {
//                dis[dest][k - 1] = d + cost;
//                // Insertion sort to keep the k distances sorted
//                for (int j = k - 1; j > 0 && dis[dest][j] < dis[dest][j - 1]; --j) {
//                    int temp = dis[dest][j];
//                    dis[dest][j] = dis[dest][j - 1];
//                    dis[dest][j - 1] = temp;
//                }
//                // Add new distance to the queue
//                pq[pqSize++] = (Pair){ dest, d + cost };
//                // Keep the priority queue sorted by distance
//                for (int j = pqSize - 1; j > 0 && pq[j].cost < pq[j - 1].cost; --j) {
//                    Pair temp = pq[j];
//                    pq[j] = pq[j - 1];
//                    pq[j - 1] = temp;
//                }
//            }
//        }
//    }
//
//    // Printing K shortest paths
//    for (int i = 0; i < k; ++i) {
//        if (dis[n][i] != INT_MAX) {
//            printf("%d ", dis[n][i]);
//        }
//        else {
//            printf("INF ");
//        }
//    }
//    printf("\n");
//
//    // Free memory
//    for (int i = 0; i <= n; ++i) {
//        free(g[i]);
//        free(dis[i]);
//    }
//    free(g);
//    free(gSize);
//    free(dis);
//    free(pq);
//}
//
//int main() {
//   
//    FILE* file = fopen("2.txt", "r");
//    if (file == NULL) {
//        perror("Error opening file");
//        return 1;
//    }
//
//    int N, M, K = 10;
//    fscanf_s(file, "# Nodes: %d Edges: %d", &N, &M);
//
//    int(*edges)[3] = (int(*)[3])malloc(M * sizeof(*edges));
//    if (edges == NULL) {
//        perror("Memory allocation failed");
//        fclose(file);
//        return 1;
//    }
//
//    // Seed the random number generator
//    srand((unsigned int)time(NULL));
//
//    int index = 0, u, v;
//    char line[128];
//    while (fgets(line, sizeof(line), file)) {
//        if (line[0] == '#') continue; // Skip comments
//        if (sscanf_s(line, "%d\t%d", &u, &v) == 2) {
//            edges[index][0] = u;
//            edges[index][1] = v;
//            // Assign a random weight between 1 and 20
//            edges[index][2] = rand() % 30 + 1;
//            index++;
//        }
//    }
//
//    fclose(file);
//
//    // Print edges with their weights
//    /*for (int i = 0; i < M; i++) {
//        printf("Edge: %d -> %d, Weight: %d\n", edges[i][0], edges[i][1], edges[i][2]);
//    }*/
//
//    printf("%d, %d, %d\n", N, M, K);
//
//    findKShortest(edges, N, M, K);
//
//    // Remember to free the allocated memory
//    free(edges);
//
//    return 0;
//}
