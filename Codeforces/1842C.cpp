#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"

const int N = 1e6;
const int INF = 1e9;
using Long = long long;

vector<int> a(N), nxt(N);

int dp[N][2], n;

int solve(int idx, int j) { 
// j: if I consider to delete the cur subgroup 
// 1 if i consider, 0 if i dont consider

	if (idx == n) return 0;
	if (dp[idx][j] != -1) return dp[idx][j];
	int ans = 0;
	if (!j) {
		ans = max(solve(idx + 1, 0), solve(idx + 1, 1));
	}
	else {
		if (nxt[idx] != -1) {
			ans = max(solve(nxt[idx] + 1, 1) , solve(nxt[idx] + 1, 0)) +  (nxt[idx] - idx + 1);		
			ans = max(ans, solve(nxt[idx], 1) + nxt[idx] - idx);
		}
	}
	
	return dp[idx][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    /*
    PROBLEM: Given an array of n numbers build a array of size n
    wich contains the index of the next element equal to the cur.
    */
	int tt; cin >> tt;
	
	while (tt--) {
		cin >> n;
		vector<int> last(n + 1, -1);
		
		//Last contains the last idx of [i]
		//next contains the next idx of a in wich a[i] = a[idx]; (i is the cur element)
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			nxt[i] = -1;
			last[i] = -1;
			dp[i][0] = dp[i][1] = -1;
		}
		last[n] = -1;
		
		for (int i = 0; i < n; i++) {
			if (last[a[i]] != -1) {
				nxt[last[a[i]]] = i;
			}
			last[a[i]] = i;
		}
		//for (int i = 0; i < n; i++) cout << nxt[i] << " ";
		cout << max(solve(0, 0), solve(0, 1)) << "\n";
		
	}
	
    return 0;
}