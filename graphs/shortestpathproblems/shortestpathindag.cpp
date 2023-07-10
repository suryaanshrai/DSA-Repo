/*
https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Shortest path in Directed Acyclic Graph
*/

// User function Template for C++
class Solution {
    void topoSort(int node, vector<pair<int, int>> adj[], stack<int> &st, vector<bool> &vis) {
        vis[node] = true;
        for (auto it:adj[node]) {
            if (!vis[it.first]) {
                topoSort(it.first, adj, st, vis);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<bool> vis(N, false);
        vector<int> topo;
        
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, st, vis);
                while (!st.empty()) {
                    topo.push_back(st.top());
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
                    topo.push_back(st.top());
                    st.pop();
                }
        vector<int> dist(N,1e7);
        dist[0] = 0;
        vector<bool> vis2(N,false);
        vis2[0] = true;
        for (auto i:topo) {
            for (auto it: adj[i]) {
                if (dist[it.first] > dist[i]+it.second) {
                    dist[it.first] = dist[i]+it.second;
                    vis2[it.first] = true;
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