/*
The below is the code to calculate the sum of fibonnacci numbers from f(n) to f(m), i.e.

Given two non-negative integers N and M (N <= M), 
you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.

The code also contains the following helpful functions:
    1. Mulitplying two matrices
    2. Calculating power of a Matrix
    3. Calculating Fibonacci number using matrix exponentiation
*/
#include <bits/stdc++.h>
#define ll unsigned long long
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

void prod(vector<vector<ll>> A, vector<vector<ll>> B, vector<vector<ll>> &res) {
    res.clear();
    for (ll i = 0; i < A.size(); i++) {
        vector<ll> temp;
        for (ll j = 0; j < B[0].size(); j++) {
            temp.push_back(0);
        }
        res.push_back(temp);
    }
    
    for (ll i = 0; i < A.size(); i++) {
        for (ll j = 0; j < B[0].size(); j++) {
            for (ll k = 0; k < B.size(); k++) {
                res[i][j] = (res[i][j]%mod + (A[i][k]%mod * B[k][j]%mod) % mod) % mod;
            }
        }
    }
}

void power(vector<vector<ll>> A, int n, unsigned long long p, vector<vector<ll>> &res) {
        res.clear();
    for (ll i = 0; i < n; i++) {
        vector<ll> temp;
        for (ll j = 0; j < n; j++) {
            if (i == j) {
                temp.push_back(1);
            }
            else {
                temp.push_back(0);
            }
        }
        res.push_back(temp);
    }

    while (p) {
        if (p % 2 == 1) {
            prod(res, A, res);
            p--;
        }
        p/=2;
        prod(A,A,A);
    }
}

unsigned long long fibo(unsigned long long n) {
    vector<vector<ll>> T = {{1, 1}, {1, 0}}, A = {{1}, {0}};
    power(T, 2, n, T);
    vector<vector<ll>> res;
    prod(T, A, res);
    return res[0][0];
}

void solve() {
    unsigned long long n, m;
    cin >> n >> m;
    cout << ((fibo(m+1)%mod - fibo(n)%mod)+mod)%mod << endl;
}

int main() {
    int t = 1;
    cin >> t;
    loop(t) { solve(); }
}
