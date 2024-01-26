// SSSP
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

void precal() {
    // TODO
}

void solve() {
    // TODO
    int v, e;
    cin >> v >> e;
    vector<pair<int,int>> adj[v];
    loop(e) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vector<int> dist(v, int(1e9));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for (auto it:adj[node]) {
            if (dist[it.first] > dist[node]+it.second) {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
    loop(v) {
        cout << i << " " << dist[i] << endl;
    }
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
