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
    // This function works for zero-based indices
    int components() {
        map<int,int> m;
        int count = 0;
        for (int i = 0; i < parent.size()-1; i++) {
            int p = find(i);
            if (m.find(p) == m.end()) {
                m[p]++;
            }
        }
        return m.size();
    }
    // this works for 1 based-indices
    int components_1() {
        map<int,int> m;
        int count = 0;
        for (int i = 1; i < parent.size(); i++) {
            int p = find(i);
            if (m.find(p) == m.end()) {
                m[p]++;
            }
        }
        return m.size();
    }
};