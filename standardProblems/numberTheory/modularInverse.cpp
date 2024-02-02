int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1, g = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
}

int modInverse(int a, int m) {
    if (m == 1) {
        return -1;
    }
    int x, y, g = gcd(a, m, x, y);
    if (g == 1) {
        return ((x%m)+m)%m;
    }
    return -1;
}