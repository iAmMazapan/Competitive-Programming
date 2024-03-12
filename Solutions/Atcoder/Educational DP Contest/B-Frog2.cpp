#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"
#define sz(v) ((int)(v).size())
#define forn(i, n) for (int i = 0; i < (int)n; i++)

const int N = 1e6;
const int INF = 1e9;
using Long = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
	
	int n; cin >> n;
	vector<int> dp(n), h(n);
	forn (i, n) cin >> h[i];
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}
	
	cout << dp[n - 1];
	
	return 0;
}