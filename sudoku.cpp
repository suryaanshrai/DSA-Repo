// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    
    // Function to return the first empty place in form of a vector
    vector<int> empty_places(int grid[N][N]) {
        vector<int> res;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
    
     // Returns true if it is possible to place val at i,j and false otherwise
    bool checkval(int row, int col, int val, int grid[N][N]) {
        // check row
        for (int i = 0; i < N; i++) {
            if (grid[i][col] == val) {
                return false;
            }
        }
        //check column
        for (int i = 0; i < N; i++) {
            if (grid[row][i] == val) {
                return false;
            }
        }
        for (int gridrow = (row/3)*3, i = gridrow; i < gridrow+3; i++) {
            for (int gridcol = (col/3)*3, j = gridcol; j < gridcol+3; j++) {
                if (grid[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Returns a vector of possible values that can be placed on that box
    vector<int> possible_values(int i, int j, int grid[N][N]) {
        vector<int> res;
        for (int k = 1; k <= 9; k++) {
            if (checkval(i,j,k, grid)) {
                res.push_back(k);
            }
        }
        return res;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code 
        vector<int> v = empty_places(grid);
        if (v.empty()) {
            return true;
        }
        vector<int> vals = possible_values(v[0], v[1], grid);
        for (auto i:vals) {
            grid[v[0]][v[1]] = i;
            if (SolveSudoku(grid)) {
                return true;
            }
        }
        grid[v[0]][v[1]] = 0;
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
