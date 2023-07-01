/*
https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column
number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. 

There should be atleast one 1 in the grid.
 
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
   public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<vector<int>> ans(grid.size(), vector<int> (grid[0].size(), 0));
	    vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
	    queue<pair<pair<int,int>,int>> q;
	    for (int i = 0; i < grid.size(); i++) {
	        for (int j = 0; j < grid[0].size(); j++) {
	            if (grid[i][j] == 1) {
	                q.push({{i,j}, 0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    while (!q.empty()) {
	        pair<pair<int,int>,int> temp=q.front();
	        q.pop();
	        int x = temp.first.first;
	        int y = temp.first.second;
	        int dx[] = {0,1,0,-1};
	        int dy[] = {1,0,-1,0};
	        for (int k = 0; k < 4; k++) {
	            if (x+dx[k] >= 0 && x+dx[k] < grid.size() &&
	               y+dy[k] >= 0 && y+dy[k] < grid[0].size() &&
	               vis[x+dx[k]][y+dy[k]] == 0) {
	                   vis[x+dx[k]][y+dy[k]] = 1;
	                   ans[x+dx[k]][y+dy[k]] = temp.second+1;
	                   q.push({{x+dx[k], y+dy[k]}, temp.second+1});
	               }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends