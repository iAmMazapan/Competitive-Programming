#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2e5 + 5;

#define debug(x) cout << #x << " = " << x <<"\n"

int lis(vector<Long> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<Long> d(n+1, INF);
    d[0] = -INF;
 
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }
 
    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
int main() {
	int t; cin >> t;
	while (t--) {
		
	}
	return 0;
}