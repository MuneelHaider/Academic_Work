#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

void findKShortest(vector<vector<pair<int, int>>>& g, int n, int k) {
    vector<vector<int>> dis(n + 1, vector<int>(k, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});  // Distance, Node

    dis[1][0] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto& [v, w] : g[u]) {
            for (int i = 0; i < k; ++i) {
                if (dis[v][i] > d + w) {
                    dis[v][i] = d + w;
                    pq.push({dis[v][i], v});
                    sort(dis[v].begin(), dis[v].end());
                    break;
                }
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        if (dis[n][i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << dis[n][i] << " ";
        }
    }
    cout << "\n";
}

vector<vector<pair<int, int>>> readGraphFromFile(const string &filename, int &n, int &m) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    n = 0;  // Initialize the number of nodes to zero.
    m = 0;  // Initialize the number of edges to zero.
    int u, v;
    vector<pair<int, int>> edges;

    while (file >> u >> v) {
        edges.emplace_back(u, v);
        n = max(n, max(u, v));
        ++m;
    }
    
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto& edge : edges) {
        g[edge.first].emplace_back(edge.second, 1);  // Assuming a default weight of 1.
    }

    file.close();
    return g;
}

int main() {
    int N, M;
    string filename = "1.txt";

    vector<vector<pair<int, int>>> graph = readGraphFromFile(filename, N, M);
    int K = 3;
    findKShortest(graph, N, K);

    return 0;
}
