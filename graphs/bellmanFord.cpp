#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int n, int m, int src, int des, vector<Edge>& edges) {
    vector<int> distance(n, INT_MAX);
    distance[src - 1] = 0;

    // Relaxation step
    for (int i = 1; i <= n - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.src - 1] != INT_MAX && distance[edge.src - 1] + edge.weight < distance[edge.dest - 1]) {
                distance[edge.dest - 1] = distance[edge.src - 1] + edge.weight;
            }
        }
    }

    // Check for negative cycles
    for (const Edge& edge : edges) {
        if (distance[edge.src - 1] != INT_MAX && distance[edge.src - 1] + edge.weight < distance[edge.dest - 1]) {
            cout << "Graph contains negative weight cycle, unable to find shortest paths." << endl;
            return;
        }
    }

    // Print the result
    if (distance[des - 1] == INT_MAX) {
        cout << (int)1e9 << endl;
    } else {
        cout << distance[des - 1] << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int src, des;
        cin >> src >> des;

        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        }

        bellmanFord(n, m, src, des, edges);
    }

    return 0;
}
