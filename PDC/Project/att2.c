#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999999

void findKShortest(int edges[][3], int n, int m, int k) {
    // Array to store up to k-shortest distances from source to each vertex
    int **dis = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dis[i] = (int*)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            dis[i][j] = 0;  // Initialize distances to INF
        }
    }

    // Source node is 1
    dis[1][0] = 0;

    // Relax edges up to k times
    for (int step = 0; step < k; step++) {
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            // Relax the edge u-v
            if (dis[u][step] != INF && dis[u][step] + wt < dis[v][k-1]) {
                dis[v][k-1] = dis[u][step] + wt;

                // Sort the array dis[v]
                for (int x = k-1; x > 0; x--) {
                    if (dis[v][x] < dis[v][x-1]) {
                        int temp = dis[v][x];
                        dis[v][x] = dis[v][x-1];
                        dis[v][x-1] = temp;
                    }
                }
            }
        }
    }

    // Print the k-shortest distances to node n
    for (int i = 0; i < k; i++) {
        if (dis[n][i] == INF)
            printf("INF ");
        else
            printf("%d ", dis[n][i]);
    }
    printf("\n");

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(dis[i]);
    }
    free(dis);
}


int main() {
    FILE *file = fopen("2.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int N, M, K = 3;
    fscanf(file, "# Nodes: %d Edges: %d", &N, &M);

    int (*edges)[3] = (int (*)[3])malloc(M * sizeof(*edges));
    if (edges == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    int index = 0, u, v;
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') continue; // Skip comments
        if (sscanf(line, "%d\t%d", &u, &v) == 2) {
            printf("%d, %d \n", u, v);
            edges[index][0] = u;
            edges[index][1] = v;
            edges[index][2] = 1; // Assume weight is 1 if not specified
            index++;
        }
    }

    findKShortest(edges, N, M, K);

    free(edges);
    fclose(file);
    return 0;
}
