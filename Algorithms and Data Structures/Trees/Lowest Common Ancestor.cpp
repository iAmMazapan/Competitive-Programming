#include<bits/stdc++.h> 
using namespace std;
 
using Long = long long;
 
#define debug(x) cout << #x << " = " << x <<"\n"
#define sz(v) ((int)(v).size())

const int N = 1e6 + 10;
const int LOG = 20;

vector<int> g[N], depth(N);
int up[N][LOG];
 
void dfs(int u, int p) {
	for (auto v : g[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			up[v][0] = u;
			for (int i = 1; i < LOG; i++) {
				up[v][i] = up[up[v][i - 1]][i - 1];
			}
			dfs(v, u);
		}
	}
}  

int get_lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int k = depth[a] - depth[b];
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			a = up[a][i];
		}
	}
	
	if (a == b) return a;
	
	for (int i = LOG - 1; i >= 0; i--) {
		if (up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q; cin >> n >> q;
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	
	while (q--) {
		cin >> u >> v;
		int node = get_lca(u, v);
		debug(node);
		cout << (depth[u] - depth[node]) + (depth[v] - depth[node]) << "\n";
	}
    return 0;
	
}