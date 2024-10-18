#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int to;
    int weight;
} Edge;

typedef struct {
    int *cost;
    int *node;
    int size;
} PriorityQueue;

void initPQ(PriorityQueue *pq, int capacity) {
    pq->cost = (int *)malloc(capacity * sizeof(int)); // Explicit casting
    pq->node = (int *)malloc(capacity * sizeof(int)); // Explicit casting
    pq->size = 0;
}

void freePQ(PriorityQueue *pq) {
    free(pq->cost);
    free(pq->node);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(PriorityQueue *pq, int cost, int node) {
    int i = pq->size++;
    pq->cost[i] = cost;
    pq->node[i] = node;
    while (i != 0 && pq->cost[(i - 1) / 2] > pq->cost[i]) {
        swap(&pq->cost[i], &pq->cost[(i - 1) / 2]);
        swap(&pq->node[i], &pq->node[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pop(PriorityQueue *pq) {
    int res = pq->node[0];
    int cost = pq->cost[0];
    pq->cost[0] = pq->cost[--pq->size];
    pq->node[0] = pq->node[pq->size];
    int i = 0, child;
    while ((child = 2 * i + 1) < pq->size) {
        if (child + 1 < pq->size && pq->cost[child + 1] < pq->cost[child]) {
            child++;
        }
        if (pq->cost[i] <= pq->cost[child]) break;
        swap(&pq->cost[i], &pq->cost[child]);
        swap(&pq->node[i], &pq->node[child]);
        i = child;
    }
    return res;
}

void findKShortest(int edges[][3], int n, int m, int k) {
    Edge **g = (Edge **)malloc((n + 1) * sizeof(Edge *)); // Explicit casting
    int *sizes = (int *)calloc(n + 1, sizeof(int));       // Explicit casting

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        g[u] = (Edge *)realloc(g[u], (sizes[u] + 1) * sizeof(Edge)); // Explicit casting
        g[u][sizes[u]++] = (Edge){edges[i][1], edges[i][2]};
    }

    int **dis = (int **)malloc((n + 1) * sizeof(int *)); // Explicit casting
    for (int i = 0; i <= n; i++) {
        dis[i] = (int *)malloc(k * sizeof(int)); // Explicit casting
        for (int j = 0; j < k; j++) {
            dis[i][j] = INF;
        }
    }
    dis[1][0] = 0;

    PriorityQueue pq;
    initPQ(&pq, m * k);
    push(&pq, 0, 1);

    while (pq.size > 0) {
        int u = pop(&pq);
        int d = pq.cost[0]; // The cost at the top of the heap after pop
        if (dis[u][k - 1] < d)
            continue;

        for (int i = 0; i < sizes[u]; i++) {
            int dest = g[u][i].to;
            int cost = g[u][i].weight;

            if (d + cost < dis[dest][k - 1]) {
                dis[dest][k - 1] = d + cost;
                for (int x = k - 1; x > 0 && dis[dest][x] < dis[dest][x - 1]; x--) {
                    swap(&dis[dest][x], &dis[dest][x - 1]);
                }
                push(&pq, dis[dest][k - 1], dest);
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

    freePQ(&pq);
    for (int i = 0; i <= n; i++) {
        free(dis[i]);
        free(g[i]);
    }
    free(dis);
    free(g);
    free(sizes);
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
    return 0;
}
