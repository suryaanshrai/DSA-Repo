#include<bits/stdc++.h>
#define M (beg+end)/2
using namespace std;

const int N = (int)(1e5+5);

int a[N];
int st[4*N];


void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = a[beg];
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = st[2*pos+1] + st[2*pos+2];
}

void update(int beg, int end, int idx, int val, int pos) {
	if(beg == end) {
		st[pos] = val;
		return;
	}

	if(idx <= M) {
		update(beg, M, idx, val, 2*pos+1);
	} else {
		update(M+1, end, idx, val, 2*pos+2);
	}

	st[pos] = st[2*pos+1] + st[2*pos+2];
}

int query(int beg, int end, int ql, int qr, int pos) {
	if(ql<=beg and qr>=end) {
		return st[pos];
	} else if(ql>end or qr<beg) {
		return 0;
	}

	return query(beg, M, ql, qr, 2*pos+1) + query(M+1, end, ql, qr, 2*pos+2);
}


signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n = 4;
	a[0] = 1;
	a[1] = 2;
	a[2] = 5;
	a[3] = 2;

	// 1 2 2 2

	build(0, n-1, 0);

	cout<<query(0, n-1, 1, 3, 0)<<"\n";

	update(0, n-1, 2, 2, 0);

	cout<<query(0, n-1, 1, 3, 0);

	return 0;
}
