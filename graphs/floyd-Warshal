// APSP
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
    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V+1, vector<int>(V+1, (int)1e9));
    loop(V+1) dist[i][i] = 0;

    loop(E) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[v][u] = dist[u][v] = min(dist[u][v], min(dist[v][u], w));
    }

    fr (i, 1, V+1) {
        fr (a, 1, V+1) {
            fr (b, 1, V+1) {
                dist[a][b] = min(dist[a][b], dist[a][i]+dist[i][b]);
            }
        }
    }

    int q;
    cin >> q;
    loop(q) {
        // Take in the query and return the distance
        int u, v;
        cin >> u >> v;
        cout << dist[u][v] << endl;
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
