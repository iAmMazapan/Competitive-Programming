#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << "\n"
const int N = 1e6 + 5;

vector<int> parent(N), cnt(N);


void make_set(int u) {
	parent[u] = u;
	cnt[u] = 1;
}
 
int find_set(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find_set(parent[u]);	
}

//Union by size
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (cnt[a] < cnt[b]) {
			swap(a, b);
		}
		parent[b] = a;
		cnt[a] += cnt[b]; 
	}	
}

int main() {
	// Basic connected components problem
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) make_set(i);
	
	int a, b;
	while (m--) {
		cin >> a >> b;
		union_sets(a, b);
	}
	
	for (int i = 1; i <= n; i++) debug(find_set(i));
	
	return 0;
}
/*
IN:
5 2
1 2
1 5

OUT:
find_set(i) = 1
find_set(i) = 1
find_set(i) = 3
find_set(i) = 4
find_set(i) = 1
*/

