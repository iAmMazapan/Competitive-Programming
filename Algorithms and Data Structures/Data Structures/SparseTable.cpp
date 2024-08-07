#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"

const int N = 1e6 + 5;
const int LOG = 20;

int st[N][LOG], a[N]; // -> stores i -> i + 2^j;
int lg[N];

//special cases : idempotent(  min, max, gcd, and , or)
int query(int l, int r) { // 0 indexed [l, r]
	int len = r - l + 1;
	int k = lg[len];
	return min(st[l][k], st[r - (1<<k) + 1][k]);	
}

int main() {
	int n; cin >> n;
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	for (int k = 1; k < LOG; k++) {
		for (int i = 0; i + (1 << k) - 1 < n; i++) {
			st[i][k] = min(st[i][k - 1], st[i + (1<<(k-1))][k - 1]);
		}
	}	
	
	int q; cin >> q;
	int l, r; 
	while (q--) {
		cin >> l >> r;
		cout << query(l, r) << "\n";
	}
	return 0;
}