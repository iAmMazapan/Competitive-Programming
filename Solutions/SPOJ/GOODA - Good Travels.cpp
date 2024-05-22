#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using Long = long long;
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define debug(x) cout << #x << " = " << x << "\n"
#define sz(v) ((Long)(v).size())
#define ff first
#define ss second
#define prec(n) fixed << setprecision(n)
 
const Long INF = 1e18;
const int N = 1e6 + 5;
const int LOG = 20;
const int MOD = 1e9 + 7;
 
Long add(Long a, Long b, Long m = 1LL*MOD) { return (a%m + b%m+2*m)%m;}
Long sbt(Long a, Long b, Long m = 1LL*MOD) { return a-b < 0 ? a-b+m : a-b; }
Long mul(Long a, Long b, Long m = 1LL*MOD) { return ((a%m+m)*(b%m+m))%m;}
 
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
template <class T>
// to use as a multiset less -> less_equal
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
tree_order_statistics_node_update>;
 
// order_of_key(val)
// find_by_order(key)
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

vector<Long> f(N + 3), dp(N), fun(N);
 

vector<int> g[N], gt[N], order, visited(N), component; 
vector<int> gscc[N];
vector<int> condensed_graph[N], parent(N);

Long bin_pow(Long a, Long b) {
	Long res = 1LL;
	while (b) {
		if (b & 1) res = res* a%MOD;
		a = a*a % MOD;
		b >>= 1;
	}
	return res;
}

Long inverse(Long a) {
	return bin_pow(a, MOD - 2)%MOD;
}

Long comb(Long n, Long k) {
	Long res = f[n];
	(res *= inverse(f[n - k])) %= MOD;
	return (res*inverse(f[k]))%MOD;
}


void dfs1(int u) {
	visited[u] = 1;
	for (auto v : g[u]) {
		if (!visited[v]) {
			dfs1(v);
		}
	}
	order.emplace_back(u);
}

void dfs2(int u) {
	visited[u] = 1;
	component.emplace_back(u);
	for (auto v : gt[u]) {
		if (!visited[v]) {
			dfs2(v);
		}
	}
}


void solve() {
	int n, m, s, e; cin >> n >> m >> s >> e;
	for (int i = 0; i < n; i++) cin >> fun[i + 1];
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].emplace_back(b);
		gt[b].emplace_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs1(i);
	}

	reverse(order.begin(), order.end()); 
	for (int i = 1; i <= n; i++) visited[i] = 0;
	for (auto u : order) {
		if(!visited[u]) {
			dfs2(u);
			Long score = 0;
			int root = component.front();
			for (auto v : component) {
				parent[v] = root;
				score += fun[v];
			}
			for (auto v : component) {
				fun[v] = score;
			}
			component.clear();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto j : g[i]) {
			if (parent[i] != parent[j]) {
				gscc[parent[i]].emplace_back(parent[j]);
			}
		}
	}

	dp[parent[s]] = fun[parent[s]];
	queue<int> q;
	q.push(parent[s]);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : gscc[u]) {
			q.push(v);
			dp[v] = max(dp[v], dp[u] + fun[v]);
		}
	}
	cout << dp[parent[e]] << "\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int tt = 1; //cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
