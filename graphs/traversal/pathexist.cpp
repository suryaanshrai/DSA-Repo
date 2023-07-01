/*
https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible 
from the source to destination. You can traverse up, down, right and left.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        pair<int,int> src, dst;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    src = {i,j};
                }
                if (grid[i][j] == 2) {
                    dst = {i,j};
                }
            }
        }
        queue<pair<int,int>> q;
        q.push(src);
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        vis[src.first][src.second] == 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == dst.first && y == dst.second) {
                return true;
            }
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
            for (int i = 0; i < 4; i++) {
                if (x+dx[i] >= 0 && x+dx[i] < grid.size() &&
                    y+dy[i] >= 0 && y+dy[i] < grid[0].size() &&
                    vis[x+dx[i]][y+dy[i]] == 0 && grid[x+dx[i]][y+dy[i]] != 0) {
                        q.push({x+dx[i], y+dy[i]});
                        vis[x+dx[i]][y+dy[i]] = 1;
                    }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends