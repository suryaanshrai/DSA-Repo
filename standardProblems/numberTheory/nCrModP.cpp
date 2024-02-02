// Fermat's little theorem to calculate (nCr % p)
unsigned long long power(int a, int b, int p) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) {
            res = ((res%p)*(a%p))%p;
            b--;
        }
        a = ((a%p)*(a%p))%p;
        b /= 2;
    }
    return res;
}

unsigned long long  fermatLittle(int n, int r, int p)
{
    // Write your code here.
    vector<long long unsigned> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (i%p*fact[i-1]%p)%p;
    }
    long long a = fact[n], b = fact[r], c = fact[n-r];
    return ((a%p) * power(b, p-2, p)* power(c, p-2, p))%p;

}
