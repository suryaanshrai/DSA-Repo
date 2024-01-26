#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for (int i = a; i < b; i++)
#define loop(n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define inf (1ll<<60)
#define all(x) (x).begin(), (x).end()

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

void precal() {
    // TODO
}

void solve() {
    // TODO
    int v, e;
    cin >> v >> e;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    loop(e) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({w, {u, v}});
    }
    DSU ds(v);
    ll weight = 0;
    while (!pq.empty()) {
        int u = pq.top().second.first, v = pq.top().second.second, w = pq.top().first;
        pq.pop();
        if (ds.find(u) != ds.find(v)) {
            ds.Union(u,v);
            weight += w;
        }
    }
    cout << weight << endl;
}

int main() {
    fast_io;
    cout << fixed;
    cout << setprecision(10);
    precal();
    int t = 1;
    cin >> t;
    loop(t) {
        solve();
    }
}
