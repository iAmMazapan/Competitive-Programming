#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"

const int N = 1e6 + 5;
const int INF = 1e9;
using Long = long long;

vector<Long> phi(N + 1), dp(N + 1);

void init() {
	for (int i = 0; i <= N; i++) {
		phi[i] = i;
	}    
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j]/i;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			//This also works
			//dp[j] += phi[j/i]*j/i;
			dp[j] += phi[i]*i;
		}
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	init();
	int tt; cin >> tt;
	while (tt--) {
		Long n; cin >> n;
		Long ans = (dp[n] - 1)*n;
		ans /= 2;
		ans += n;
		cout << ans << "\n";
	}
	return 0;
}
