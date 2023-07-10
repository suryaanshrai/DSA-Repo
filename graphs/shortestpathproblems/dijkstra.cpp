/*
https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where
 adj[i] is a list of lists containing two integers where the first integer of each list j denotes 
 there is edge between i and j , second integers corresponds to the weight of that  edge . You 
 are given the source vertex S and You to Find the shortest distance of all the vertex's from the
  source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    class comparator {
        public:
        bool operator()(vector<int> a, vector<int> b){
            return a[1] < b[1];
        }
    };
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e7);
        pq.push({0,S});
        dist[S] = 0;
        while (!pq.empty()) {
            
            for (auto it:adj[pq.top().second]) {
                if (dist[it[0]] > pq.top().first + it[1]) {
                    dist[it[0]] = pq.top().first + it[1];
                    pq.push({dist[it[0]], it[0]});
                }
            }
            pq.pop();
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e7) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends