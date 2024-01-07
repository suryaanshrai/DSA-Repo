long long int power(long long int x, long long int y, long long int p) {
	long long int res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1) {
			res = (res * x) % p;
		}
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

long long int modInverse(long long int a, long long int p) {
	return power(a, p - 2, p);
}

long long int modMultiplication(long long int a, long long int b, long long int m) {
	a = a % m;
	b = b % m;
	return (((a * b) % m) + m) % m;
}

long long int modDivision(long long int a, long long int b, long long int m) {
	a = a % m;
	b = b % m;
	return (modMultiplication(a, modInverse(b, m), m) + m) % m;
}
