// https://practice.geeksforgeeks.org/problems/word-search/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Solution {

 // This function tests whether the word exists for the particular index or not and can be considered the primary function of the code
 // as it is the one which recursively calls itself and tests the presence or absence of the word
    bool findWord(int i, int j, vector<vector<char>> board, string word, 
        int index, vector<vector<bool>> &vis) {
  
//delta arrays to check around the indices (i,j) for the presence of the next letter of the word
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
// loops over the delta array to get the indices adjacent to (i,j)
        for (int k = 0; k < 4; k++) {

            if (i+dx[k] >= 0 && i+dx[k] < board.size() &&
                j+dy[k] >= 0 && j+dy[k] < board[0].size() &&
                !vis[i+dx[k]][j+dy[k]]) {

// when the index is not visited and the next letter of the word is there on that index, we proceed as follows:
                    if (board[i+dx[k]][j+dy[k]] == word[index]) {

// In case the end of the word is reached, we have found the word and hence, return true
                        if (index == word.length()-1) {
                           return true;
                        }

// Otherwise, we mark the presence of this letter of the word and search for the next letter in the adjacent cells
                        vis[i+dx[k]][j+dy[k]] = true;
                        if (findWord(i+dx[k], j+dy[k], board, word, index+1, vis)) {
                            return true;
                        }

// In case the word is not formed in this search, we revert the value of vis to false, unmarking this letter for further searches
                        vis[i+dx[k]][j+dy[k]] = false;
                    }

// Note: We had already checked the presence of word[index] (the present letter of the word) in the if conditional within which these two ifs are nested
                }
        }
        return false;
    }
public:

// This is the driver function
    bool isWordExist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false)); // Vector to keep track of letters that have been visited on the word
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

// if the word's first letter exists on the board for this particular index we go on to check around it for the presence of the entire word
                if (board[i][j] == word[0]) {

// in case the word is of length of 1 we've already found it and hence returning true
                    if (word.length() == 1) {
                        return true;
                    }

// marking the vis[][] array as true so that we may not add this letter again
                    vis[i][j] = true;

// recursive call to the function which checks the presence of the word around this letter
// the index has been incremented already, as that is how i wrote the function. It just makes things easier :)
                    if(findWord(i, j, board, word, 1, vis)) {
                        return true;
                    }
// Unmarking the vis[][] array in case the word was not found so that this letter may be used in further searches of the word
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
// Hope this helped ; )




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends