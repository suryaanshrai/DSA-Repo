//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


// } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // 	Write your code herec
        vector<int> adj[n];
        for (auto edge:dependency) {
            adj[edge.first].push_back(edge.second);
        }
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it:adj[i]) {
                indegree[it]++;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(n,false);
        for (int i = 0;i < n; i++) {
            if (indegree[i] == 0) {
                pq.push({duration[i], i});
                vis[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << i << " " << duration[i] << ": ";
            for (auto it: adj[i]) {
                cout << it << " ";
            }
            cout << endl;
        }
        int mintime=0;
        while (!pq.empty()) {
            cout << "Top of pq: ";
            cout << pq.top().first << " " << pq.top().second << endl;
            // cout << "edges: ";
            for (auto it: adj[pq.top().second]) {
                indegree[it]--;
                //cout << "indegree of" << it << " " << indegree[it];
                if (indegree[it] == 0) {
                    pq.push({duration[it]+pq.top().first, it});
                    vis[it] = true;
                }
            }
            if (mintime < pq.top().first) {
                mintime = pq.top().first;
            }
            cout << "\n\n";
            pq.pop();
        }
        for (auto it:vis) {
            if (!it) {
                return -1;
            }
        }
        return mintime;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends