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
const int N = 2e5 + 5;
const int LOG = 20;
const int MOD = 998244353;
 
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
 
Long bin_pow(Long a, Long b) {
	Long res = 1LL;
	while (b) {
		if (b & 1) res = res* a%MOD;
		a = a*a % MOD;
		b >>= 1;
	}
	return res;
}

vector<Long> f(N + 3), phi(N + 1), dp(N + 1);

Long inverse(Long a) {
	return bin_pow(a, MOD - 2)%MOD;
}

void init() {
	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = f[i - 1]*i;
		f[i] %= MOD;
	}
}

Long comb(Long n, Long k) {
	Long res = f[n];
	(res *= inverse(f[n - k])) %= MOD;
	return (res*inverse(f[k]))%MOD;
}

void sieve() {
	for (int i = 1; i <= N; i++) phi[i] = i;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j]/i;
			}
		}
		dp[i] = phi[i];
		dp[i] += dp[i - 1];
	}
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     
	sieve();
    int tt = 20; cin >> tt;
    
    for (int i = 1; i <= tt; i++) {
    	Long n; cin >> n;
    	cout << "Case " << i << ": " << n*(n + 1)/2 - dp[n] << "\n";
    }
    
    return 0;
}