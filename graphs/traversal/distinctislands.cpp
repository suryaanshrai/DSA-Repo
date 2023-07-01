/*
https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

Given a boolean 2D matrix grid of size n * m. You have to find the number of 
distinct islands where a group of connected 1s (horizontally or vertically) 
forms an island. Two islands are considered to be distinct if and only if one 
island is not equal to another (not rotated or reflected).

*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
     void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis,
        vector<pair<int,int>> &v, int x, int y, int i ,int j) {
            vis[i][j] = 1;
            v.push_back({i-x, j-y});
            
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
            
            for (int k = 0; k < 4; k++) {
                if (i+dx[k] >= 0 && i+dx[k] < grid.size() &&
                    j+dy[k] >= 0 && j+dy[k] < grid[0].size() &&
                    grid[i+dx[k]][j+dy[k]] == 1 &&
                    !vis[i+dx[k]][j+dy[k]]) {
                        dfs(grid, vis, v, x, y, i+dx[k], j+dy[k]);
                    }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        set<vector<pair<int,int>>> s;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int,int>> v;
                    dfs(grid,vis,v,i,j, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends