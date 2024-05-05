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

vector<Long> f(N + 3);
 
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


void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 

    int tt = 1; //cin >> tt;
    while (tt--) {
    	solve();	
    }
    
    return 0;
}