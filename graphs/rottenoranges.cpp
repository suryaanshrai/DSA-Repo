// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        for (int i =0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int maxt=0;
        while (!q.empty()) {
            pair<pair<int,int>,int> temp = q.front();
            q.pop();
            
            if (temp.second > maxt) {
                maxt = temp.second;
            }
            
            int x = temp.first.first;
            int y = temp.first.second;
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
            
            for (int i = 0; i < 4; i++){
                if (dx[i]+x >= 0 && dx[i]+x < grid.size() && 
                    dy[i]+y >= 0 && dy[i]+y < grid[0].size()) {
                        if (grid[dx[i]+x][dy[i]+y] == 1 && vis[x+dx[i]][y+dy[i]]==0) {
                            vis[x+dx[i]][y+dy[i]] = 1;   
                            q.push({{x+dx[i], y+dy[i]}, temp.second+1});
                        }
                }   
            }
        }
        for (int i =0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    return -1;
                }        
            }
        }
        return maxt;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends