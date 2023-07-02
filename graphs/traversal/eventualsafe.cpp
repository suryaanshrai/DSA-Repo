/*
https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int node, vector<bool> &vis, vector<bool> &safe,vector<int> adj[]) {
        vis[node] = true;
        if (adj[node].empty()) {
            safe[node] = true;
            return true;
        }
        for (int it:adj[node]) {
            if (!vis[it]) {
                safe[it] = dfs(it, vis,safe,adj);
                }
            }
        safe[node] = true;
        for (int it:adj[node]) {
            safe[node] = safe[node] && safe[it];
        }
        return safe[node];
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> safe(V,false);
        vector<bool> vis(V,false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, safe, adj);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends