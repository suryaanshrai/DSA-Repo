#include <queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int e, int v) {
    // Write your code here!
    vector<int> adj[v];
	for (auto it:edges) {
		adj[it[0]].push_back(it[1]);
	}
	vector<int> indegree(v, 0);
	for (int i = 0; i < v; i++) {
		for (int it:adj[i]) {
			indegree[it]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> topoOrder;
	while (!q.empty()) {
		int node = q.front();
		topoOrder.push_back(node);
		q.pop();
		for (auto it:adj[node]) {
			indegree[it]--;
                        if (indegree[it] == 0) {
                          q.push(it);
                        }
                }
        }
        return topoOrder;
}