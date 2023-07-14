/*
Shortest path in Undirected Graph having unit distance
https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
*/

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        vector<bool> vis2(N, false);
        vector<int> dist(N, 1e7);
        q.push(src);
        dist[src] = 0;
        vis2[src] = true;

        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (auto it:adj[temp]) {
                if (dist[temp]+1 < dist[it]) {
                    dist[it] = dist[temp]+1;
                    vis2[it] = true;
                    q.push(it);
                }
            }
        }       

        for (int i = 0; i < N; i++) {
            if (!vis2[i]) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};