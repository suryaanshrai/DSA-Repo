#include<bits/stdc++.h>
#define M (beg+end)/2
using namespace std;

const int N = (int)(1e5+5);

int a[N];
int st[4*N];
int lazy[4*N];

void pushdown(int pos, int beg, int end) {
	if(lazy[pos] > 0) {
		st[pos] += (end-beg+1) * lazy[pos];
		if(beg != end) {
			lazy[2*pos+1] += lazy[pos];
			lazy[2*pos+2] += lazy[pos];
		}
		lazy[pos] = 0;
	}
}

void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = a[beg];
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = st[2*pos+1] + st[2*pos+2];
}

void update(int beg, int end, int ul, int ur, int val, int pos) {
	pushdown(pos, beg, end);
	if(ul <= beg and ur >= end) {
		lazy[pos] += val;
		pushdown(pos, beg, end);
		return;
	}

	if(ul > end or ur < beg) return;

	update(beg, M, ul, ur, val, 2*pos+1);
	update(M+1, end, ul, ur, val, 2*pos+2);
	st[pos] = st[2*pos+1] + st[2*pos+2];
}

int query(int beg, int end, int ql, int qr, int pos) {
	pushdown(pos, beg, end);
	if(ql <= beg and qr >= end) {
		return st[pos];
	}

	if(ql > end or qr < beg) return 0;

	return query(beg, M, ql, qr, 2*pos+1) + query(M+1, end, ql, qr, 2*pos+2);
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	a[0] = 1;
	a[1] = 5;
	a[2] = 3;
	a[4] = 2;
	build(0, 3, 0);
	cout<< query(0, 3, 0, 2, 0) <<"\n";
	update(0, 3, 1, 2, 2, 0);
	cout<< query(0, 3, 0, 2, 0) <<"\n";

	return 0;
}
// [1, 7, 5, 2]
