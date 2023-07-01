// This program returns the number of groups of 1 in a matrice that are not adjacent to the boundary

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int ans = 0;
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    //implement bfs such that if no cell exists on this
                    //land adjacent to the boundary then the size of the land
                    //is added to ans;
                    int size = 0;
                    bool bound = false; // boundary land present or not
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        pair<int,int> temp = q.front();
                        q.pop();
                        size++;
                        int x = temp.first;
                        int y = temp.second;                    
                        if (x == 0 || x == grid.size()-1 || y == 0 || y == grid[0].size()-1) {
                            bound = true;
                        }
                        
                        int dx[] = {1,0,-1,0};
                        int dy[] = {0,1,0,-1};
                        
                        for (int k = 0; k < 4; k++) {
                            if (x+dx[k] >= 0 && x+dx[k] < grid.size() && 
                                y+dy[k] >= 0 && y+dy[k] < grid[0].size() &&
                                vis[x+dx[k]][y+dy[k]] == 0 && grid[x+dx[k]][y+dy[k]] == 1) {
                                    q.push({x+dx[k], y+dy[k]});
                                    vis[x+dx[k]][y+dy[k]] = 1;
                                }
                        }
                    }
                    if (!bound) {
                        ans += size;
                    }
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends