#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"
#define sz(v) ((int)(v).size())
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

using ll = long long;
const int N = 1e5;
const ll MOD = 998244353;
const ll INF = 1e10;

int dp[N];

int main() {
	fastio;
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	
	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}

	cout << dp[n - 1];
}