#include <bits/stdc++.h>
using namespace std;

using Long = long long;
const Long MOD = 1e9 + 7;
const int N = 1e6 + 10;

#define debug(x) cout << #x << " = " << x << "\n"

vector<int> phi(N + 5), depth(N + 5), g[21];


/*
	PROBLEM: https://www.spoj.com/problems/ETFD/
	First solve this: https://www.spoj.com/problems/ETF/
*/

int eulerTotient(int n) { //O(sqrt(n))
	int ans = n;
	for (int i = 2; i*n <= n; i++) {
		if (n%i == 0) {
			while (n%i == 0) {
				n /= i;
			}
			ans -= ans/i;
		}
	}
	return ans;
}

void eulerTotientSieve(int n) { //O(nloglogn)
	for (int i = 0; i <= n; i++) {
		phi[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i) {
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int getDepth(int n) {
	if (n == 1) return 0;
	return getDepth(phi[n]) + 1;
}

void solve() {
	int m, n, k; cin >> m >> n >> k; 
		
	int l = 0, r = (int)g[k].size() - 1;
	
	while (l <= r) {
		int mid = (l + r + 1) >> 1;
		if (g[k][mid] >= m) r = mid - 1;
		else l = mid + 1;
	}
	int left = r + 1;
	
	l = 0, r = (int)g[k].size() - 1;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (g[k][mid] <= n) l = mid + 1;
		else r = mid - 1;
	}
	int right = l - 1;
	
	cout << right - left + 1 << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	eulerTotientSieve(N);
	
	for (int i = 1; i <= N; i++) {
		g[getDepth(i)].emplace_back(i);
	}
	
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}