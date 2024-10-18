// // C++ implementation of above approach
// #include <bits/stdc++.h>
// using namespace std;

// #include <stdio.h>
// #include <stdlib.h>

// #define INF 1000000000

// typedef struct {
//     int vertex;
//     int weight;
// } Edge;

// typedef struct {
//     Edge* edges;
//     int size;
//     int capacity;
// } AdjList;

// typedef struct {
//     int cost;
//     int vertex;
// } Node;

// // Comparison function for the priority queue
// int compare(const void *a, const void *b) {
//     Node *nodeA = (Node *)a;
//     Node *nodeB = (Node *)b;
//     return nodeA->cost - nodeB->cost;
// }

// void push(Node heap[], int *size, Node value) {
//     heap[*size] = value;
//     int current = *size;
//     while (current > 0 && compare(&heap[current], &heap[(current - 1) / 2]) < 0) {
//         Node temp = heap[current];
//         heap[current] = heap[(current - 1) / 2];
//         heap[(current - 1) / 2] = temp;
//         current = (current - 1) / 2;
//     }
//     (*size)++;
// }

// Node pop(Node heap[], int *size) {
//     Node min = heap[0];
//     (*size)--;
//     heap[0] = heap[*size];
//     int current = 0;
//     while (2 * current + 1 < *size) {
//         int child = 2 * current + 1;
//         if (child + 1 < *size && compare(&heap[child + 1], &heap[child]) < 0) {
//             child++;
//         }
//         if (compare(&heap[current], &heap[child]) <= 0) {
//             break;
//         }
//         Node temp = heap[current];
//         heap[current] = heap[child];
//         heap[child] = temp;
//         current = child;
//     }
//     return min;
// }

// void addEdge(AdjList *graph, int u, int v, int w) {
//     if (graph[u].size == graph[u].capacity) {
//         graph[u].capacity *= 2;
//         graph[u].edges = (Edge *)realloc(graph[u].edges, graph[u].capacity * sizeof(Edge));
//     }
//     graph[u].edges[graph[u].size].vertex = v;
//     graph[u].edges[graph[u].size].weight = w;
//     graph[u].size++;
// }

// void findKShortest(int edges[][3], int n, int m, int k) {
//     // Initialize graph
//     AdjList *graph = (AdjList *)malloc((n + 1) * sizeof(AdjList));
//     for (int i = 1; i <= n; i++) {
//         graph[i].edges = (Edge *)malloc(10 * sizeof(Edge)); // Initial capacity
//         graph[i].size = 0;
//         graph[i].capacity = 10;
//     }
    
//     for (int i = 0; i < m; i++) {
//         addEdge(graph, edges[i][0], edges[i][1], edges[i][2]);
//     }

//     // Initialize distances
//     int dis[n + 1][k];
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j < k; j++) {
//             dis[i][j] = INF;
//         }
//     }
//     dis[1][0] = 0;

//     // Priority queue
//     Node heap[m * k];
//     int heapSize = 0;
//     Node start = {0, 1};
//     push(heap, &heapSize, start);

//     while (heapSize > 0) {
//         Node current = pop(heap, &heapSize);
//         int u = current.vertex;
//         int d = current.cost;

//         if (dis[u][k - 1] < d) {
//             continue;
//         }

//         for (int i = 0; i < graph[u].size; i++) {
//             int dest = graph[u].edges[i].vertex;
//             int cost = graph[u].edges[i].weight;
            
//             if (d + cost < dis[dest][k - 1]) {
//                 dis[dest][k - 1] = d + cost;
//                 qsort(dis[dest], k, sizeof(int), compare);
//                 Node new_node = {dis[dest][k - 1], dest};
//                 push(heap, &heapSize, new_node);
//             }
//         }
//     }

//     // Print K shortest paths
//     for (int i = 0; i < k; i++) {
//         printf("%d ", dis[n][i]);
//     }
//     printf("\n");

//     // Free memory
//     for (int i = 1; i <= n; i++) {
//         free(graph[i].edges);
//     }
//     free(graph);
// }

// int main() {
//     int edges[][3] = {{1, 2, 10}, {1, 3, 15}, {2, 4, 12}, {3, 4, 10}, {4, 5, 5}, {3, 5, 10}};
//     int n = 5, m = 6, k = 3;
//     findKShortest(edges, n, m, k);
//     return 0;
// }

// // Function to find K shortest path lengths
// // void findKShortest(int edges[][3], int n, int m, int k)
// // {

// // 	// Initialize graph
// // 	vector<vector<pair<int, int> > > g(n + 1);
// // 	for (int i = 0; i < m; i++) {
// // 		// Storing edges
// // 		g[edges[i][0]].push_back(
// // 			{ edges[i][1], edges[i][2] });
// // 	}

// // 	// Vector to store distances
// // 	vector<vector<int> > dis(n + 1, vector<int>(k, 1e9));

// // 	// Initialization of priority queue
// // 	priority_queue<pair<int, int>, vector<pair<int, int> >,
// // 				greater<pair<int, int> > >
// // 		pq;
// // 	pq.push({ 0, 1 });
// // 	dis[1][0] = 0;

// // 	// while pq has elements
// // 	while (!pq.empty()) {
// // 		// Storing the node value
// // 		int u = pq.top().second;

// // 		// Storing the distance value
// // 		int d = (pq.top().first);
// // 		pq.pop();
// // 		if (dis[u][k - 1] < d)
// // 			continue;
// // 		vector<pair<int, int> > v = g[u];

// // 		// Traversing the adjacency list
// // 		for (int i = 0; i < v.size(); i++) {
// // 			int dest = v[i].first;
// // 			int cost = v[i].second;

// // 			// Checking for the cost
// // 			if (d + cost < dis[dest][k - 1]) {
// // 				dis[dest][k - 1] = d + cost;

// // 				// Sorting the distances
// // 				sort(dis[dest].begin(), dis[dest].end());

// // 				// Pushing elements to priority queue
// // 				pq.push({ (d + cost), dest });
// // 			}
// // 		}
// // 	}

// // 	// Printing K shortest paths
// // 	for (int i = 0; i < k; i++) {
// // 		cout << dis[n][i] << " ";
// // 	}
// // }

// // Driver Code
// int main()
// {

// 	// Given Input
// FILE *file = fopen("2.txt", "r");
//     if (file == NULL) {
//         perror("Error opening file");
//         return 1;
//     }

//     int N, M, K = 3;

//     fscanf(file, "");
//     fscanf(file, "");
//     fscanf(file, "# Nodes: %d Edges: %d", &N, &M);

//     int (*edges)[3] = (int (*)[3])malloc(M * sizeof(*edges));
//     if (edges == NULL) {
//         perror("Memory allocation failed");
//         fclose(file);
//         return 1;
//     }

//     int index = 0, u, v;
//     char line[128];
//     while (fgets(line, sizeof(line), file)) {
//         if (line[0] == '#') continue; // Skip comments
//         if (sscanf(line, "%d\t%d", &u, &v) == 2) {

//             printf("%d, %d\n", u, v);
//             edges[index][0] = u;
//             edges[index][1] = v;
//             edges[index][2] = 1; // Assume weight is 1 if not specified
//             index++;
//         }
//     }

//     printf("%d, %d", N, M);

// 	// Function Call
// 	findKShortest(edges, N, M, K);

// 	return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} AdjList;

typedef struct {
    int priority;
    int node;
} QueueNode;

typedef struct {
    QueueNode* elements;
    int size;
    int capacity;
} PriorityQueue;

void push(PriorityQueue* pq, QueueNode node) {
    if (pq->size >= pq->capacity) {
        pq->capacity *= 2;
        pq->elements = (QueueNode*) realloc(pq->elements, pq->capacity * sizeof(QueueNode));
    }
    pq->elements[pq->size] = node;
    int current = pq->size;
    while (current > 0 && pq->elements[current].priority < pq->elements[(current - 1) / 2].priority) {
        QueueNode temp = pq->elements[(current - 1) / 2];
        pq->elements[(current - 1) / 2] = pq->elements[current];
        pq->elements[current] = temp;
        current = (current - 1) / 2;
    }
    pq->size++;
}

QueueNode pop(PriorityQueue* pq) {
    QueueNode top = pq->elements[0];
    pq->size--;
    pq->elements[0] = pq->elements[pq->size];
    int current = 0;
    while (2 * current + 1 < pq->size) {
        int child = 2 * current + 1;
        if (child + 1 < pq->size && pq->elements[child + 1].priority < pq->elements[child].priority) {
            child++;
        }
        if (pq->elements[current].priority <= pq->elements[child].priority) {
            break;
        }
        QueueNode temp = pq->elements[current];
        pq->elements[current] = pq->elements[child];
        pq->elements[child] = temp;
        current = child;
    }
    return top;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void addEdge(AdjList* adjList, int node, int weight) {
    if (adjList->size >= adjList->capacity) {
        adjList->capacity *= 2;
        adjList->edges = (Edge*) realloc(adjList->edges, adjList->capacity * sizeof(Edge));
    }
    adjList->edges[adjList->size].node = node;
    adjList->edges[adjList->size].weight = weight;
    adjList->size++;
}

void findKShortest(AdjList* graph, int n, int k) {
    int** dis = (int**) malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dis[i] = (int*) malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            dis[i][j] = INT_MAX;
            printf("%d\n",dis[i][j]);
        }
    }
    PriorityQueue pq;
    pq.elements = (QueueNode*) malloc(100 * sizeof(QueueNode));  // Initial capacity
    pq.size = 0;
    pq.capacity = 100;

    push(&pq, (QueueNode){0, 1});
    dis[1][0] = 0;

    while (!isEmpty(&pq)) {
        QueueNode top = pop(&pq);
        int d = top.priority;
        int u = top.node;

        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].node;
            int w = graph[u].edges[i].weight;
            for (int j = 0; j < k; j++) {
                if (dis[v][j] > d + w) {
                    dis[v][j] = d + w;
                    push(&pq, (QueueNode){dis[v][j], v});
                    break;
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (dis[n][i] == INT_MAX) {
            printf("INF ");
        } else {
            printf("%d\n ", dis[n][i]);
        }  
    }
    printf("\n");

    for (int i = 0; i <= n; i++) {
        free(dis[i]);
    }
    free(dis);
    free(pq.elements);
}

AdjList* readGraphFromFile(const char *filename, int *n, int *m) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    *n = 0;  // Initialize the number of nodes to zero.
    *m = 0;  // Initialize the number of edges to zero.
    int u, v;
    fscanf(file, "# Nodes: %d Edges: %d", n, m);
    AdjList* graph = (AdjList*) malloc(*m * sizeof(AdjList)); // Allocate initial memory for the graph
    if (!graph) {
        perror("Failed to allocate memory for graph");
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < *m; i++) {
        graph[i].edges = (Edge*) malloc(10 * sizeof(Edge));  // Allocate memory for edges
        graph[i].size = 0;
        graph[i].capacity = 10;
        if (!graph[i].edges) {
            perror("Failed to allocate memory for edges");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(graph[j].edges);
            }
            free(graph);
            fclose(file);
            exit(1);
        }
    }

    // Use "%d\t%d" if your data is strictly tab-separated
    // Or use " %d %d" to skip any whitespaces including tabs and spaces
    while (fscanf(file, "%d\t%d", &u, &v) == 2) {
        addEdge(&graph[u], v, 1);  // Assuming a default weight of 1.
        *n = (*n > u ? *n : u);
        *n = (*n > v ? *n : v);
        (*m)++;
        printf("%d, %d\n", u, v);
    }

    if (ferror(file)) {
        perror("Error while reading the file");
        fclose(file);
        exit(1);
    }

    printf("Finished reading the file. Nodes: %d, Edges: %d\n", *n, *m);

    fclose(file);
    return graph;
}


int main() {
    int N, M;
    const char *filename = "1.txt";

    printf("Reading graph from file: %s\n", filename);
    AdjList* graph = readGraphFromFile(filename, &N, &M);
    printf("Read graph with %d nodes and %d edges.\n", N, M);

    if (N == 0) {
        printf("No nodes read from file, please check file contents and format.\n");
        return 1; // Exit if no nodes were read to indicate an error
    }

    int K = 3;
    printf("Finding the %d shortest paths in the graph.\n", K);
    findKShortest(graph, N, K);

    printf("Freeing memory and exiting.\n");
    for (int i = 0; i <= N; i++) {
        free(graph[i].edges);
    }
    free(graph);

    return 0;
}