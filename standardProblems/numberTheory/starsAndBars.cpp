#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mod = 1e9 + 7;

void fac_(ll fac[], int size)
{
    fac[0] = 1;

    for (int i = 1; i < size; i++) 
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}

ll power(ll a, ll b, ll mod)
{
    if (b == 0) 
    {
        return 1;
    }
    
    ll ans = power(a, b / 2, mod);
    
    ans = (ans * ans) % mod;
    
    if (b % 2) 
    {
        ans = (ans * a) % mod;
    }
    return ans;
}

int main()
{
    int t;

    cin >> t;

    ll fac[200001];

    fac_(fac, 200001);

    while (t--) 
    {
        int n, k;
    
        cin >> n >> k;
    
        ll ans = fac[n + k - 1];
        ll a = fac[n], b = fac[k - 1];
    
        a = (a * b) % mod;
        a = power(a, mod - 2, mod);
    
        ans = (ans * a) % mod;
    
        cout << ans << endl;
    }
}
