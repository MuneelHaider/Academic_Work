#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999999

void findKShortest(int edges[][3], int n, int m, int k) {
    // Array to store up to k-shortest distances from source to each vertex
    int dis[n + 1][k];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dis[i][j] = INF;  // Initialize distances to INF
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
            if (dis[u][step] != INF && dis[u][step] + wt < dis[v][k - 1]) {
                dis[v][k - 1] = dis[u][step] + wt;

                // Sort the array dis[v]
                for (int x = k - 1; x > 0; x--) {
                    if (dis[v][x] < dis[v][x - 1]) {
                        int temp = dis[v][x];
                        dis[v][x] = dis[v][x - 1];
                        dis[v][x - 1] = temp;
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
}

int main() {
    int N = 4, M = 6, K = 3;
    int edges[6][3] = { {1, 2, 1}, {1, 3, 3}, {2, 3, 2}, {2, 4, 6}, {3, 2, 8}, {3, 4, 1} };

    findKShortest(edges, N, M, K);
    return 0;
}
