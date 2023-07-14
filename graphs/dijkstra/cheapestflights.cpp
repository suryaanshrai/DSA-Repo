//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
         vector<pair<int,int>> adj[n];
        for (auto flight:flights) {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> cost(n, 1e9);
        q.push({0,{src,0}});
        cost[src] = 0;
        while (!q.empty()) {
            int airport = q.front().second.first;
            int currcost = q.front().second.second;
            int stops = q.front().first;
            q.pop();
            if (stops > K) {
                continue;
            }
            for (auto flight:adj[airport]) {
                if (cost[flight.first] > currcost+flight.second) {
                    cost[flight.first] = currcost+flight.second;
                    q.push({stops+1,{flight.first, currcost+flight.second}});
                }
            }
        }
        // for (auto i: cost) cout << i << " ";
        cout <<endl;
        if (cost[dst]  == 1e9) {
            return -1;
        }
        return cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends