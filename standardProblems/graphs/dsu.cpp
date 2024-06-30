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
