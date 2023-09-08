//https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int N) {
        parent.resize(N+1);
        rank.resize(N+1);
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }
    }
    int find(int X) {
        if (parent[X] == X) {
            return X;
        }
        return parent[X] = find(parent[X]);
    }
    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } 
        else if(rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[px] = py;
            rank[py]++;
        }
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int N) {
        int m = -1, n = -1;
        // Finding max and min of rows and columns
        for (auto i:stones) {
            if (m < i[0]) {
                m = i[0];
            }
            if (n < i[1]) {
                n = i[1];
            }
        }
        DSU ds(m+n+1);
        // Unifying rows and columns of the stones. This will help us find unique parents, as stones that would be part of the same
        // row or column would become part of the same graph and hence will share the same ultimate parent
        for (auto i:stones) {
            ds.Union(i[0],i[1]+m+1);
        }
        set<int> parents;
        // finding unique parents
        for (auto i:stones) {
            parents.insert(ds.find(i[0]));
            parents.insert(ds.find(i[1]+m+1));
        }
        return stones.size()-parents.size();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}