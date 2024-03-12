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
	int a[n][3], dp[n][3];
	
	forn (i, n) {
		forn (j, 3) {
			cin >> a[i][j];
			dp[i][j] = 0;
		}
	} 
	
	
	forn (i, 3) dp[0][i] = a[0][i];
	
	for (int i = 1; i < n; i++) {
		forn (j, 3) {
			forn (k, 3) {
				if (k != j) dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
			}
		}
	}
	
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
	
	return 0;
}