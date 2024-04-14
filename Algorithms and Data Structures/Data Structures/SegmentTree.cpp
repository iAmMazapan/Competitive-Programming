#include<bits/stdc++.h> 
using namespace std;

#define debug(x) cout << #x << " = " << x << "\n"

struct SegmentTree{
	vector<int> tree;
	int n;
	SegmentTree(int n) : n(n), tree(2*n + 5, 0) {}
	
	void update(int p, int val) {
		p += n;
		for (tree[p] = val; p > 1; p >>= 1) {
			tree[p>>1] = min(tree[p], tree[p^1]);
		}
	}
	
	int query(int l, int r) { //[r, l)
		int res = 1e9;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = min(res, tree[l++]);
			if (r & 1) res = min(res, tree[--r]);
		}
		return res;
	}
};

int main() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	SegmentTree st(n);
	for (int i = 0; i < n; i++) st.update(i, a[i]);
	for (int i = 0; i < 2*n; i++) {
		//cout << st.tree[i] << " ";
	}
	while (q--) {
		int pos, val, l, r;
		int q_type; cin >> q_type;
		if (q_type&1) {
			cin >> pos >> val;
			st.update(pos - 1, val);
		}
		else {
			cin >> l >> r;
			l--;
			cout << st.query(l, r) << "\n";
		}
	}
}

/*
IN:

queries of type 1 and 2:
1 : update(pos, val)
2 : get_min(l, r) [l, r]

	10 7
	5 2 1 8 4 0 8 2 8 6
	2 1 2
	1 2 3
	2 1 2
	2 3 5
	2 3 6
	1 6 10
	2 1 10
	
OUT:
	2
	3
	1
	0
	1
	
*/