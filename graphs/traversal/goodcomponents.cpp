/*
https://practice.geeksforgeeks.org/problems/1a4b617b70f0142a5c2b454e6fbe1b9a69ce7861/1

Given an undirected graph with V vertices(numbered from 1 to V) and E edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is a fully connected component.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between
 every pair of vertices in a component, the given graph can be a disconnected graph. Consider the adjacency list from vertices 1.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> vis(V+1, false);
        int count = 0;
        vis[0] = true;
        for (int i = 1; i <= V; i++) {
            if (!vis[i]) {
                int edges = 0, ver = 0;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                ver++;
                while (!q.empty()) {
                    int temp = q.front();
                    q.pop();
                    for (int x:adj[temp]) {
                        edges++;
                        if (!vis[x]) {
                            q.push(x);
                            vis[x] = true;
                            ver++;
                        }
                    }
                }
                edges /= 2;
                if (edges == (ver*(ver-1))/2) {
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends