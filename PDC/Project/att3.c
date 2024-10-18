#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

void findKShortest(int edges[][3], int n, int m, int k) {
    int **dis = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dis[i] = (int*)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            dis[i][j] = INF;  // Initialize distances to INF
        }
    }

    dis[1][0] = 0;  // Starting node

    for (int step = 0; step < k; step++) {
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if (dis[u][step] != INF && dis[u][step] + wt < dis[v][k-1]) {
                dis[v][k-1] = dis[u][step] + wt;
                // Bubble sort the last element in the right place
                for (int x = k-1; x > 0 && dis[v][x] < dis[v][x-1]; x--) {
                    int temp = dis[v][x];
                    dis[v][x] = dis[v][x-1];
                    dis[v][x-1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (dis[n][i] == INF)
            printf("INF ");
        else
            printf("%d ", dis[n][i]);
    }
    printf("\n");

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

    int index = 0, u, v, wt;
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') continue; // Skip comments
        if (sscanf(line, "%d %d %d", &u, &v, &wt) == 3) {
            edges[index][0] = u;
            edges[index][1] = v;
            edges[index][2] = wt;
            index++;
        }
    }

    findKShortest(edges, N, M, K);

    free(edges);
    fclose(file);
    return 0;
}
