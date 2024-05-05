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
vector<Long> phi(N + 1), dp(N + 1);

void init(int n) {
	for (int i = 1; i <= n; i++) phi[i] = i;	
	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i) {
				phi[j] -= phi[j]/i;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			dp[j] +=((Long)i*phi[j/i]);
		}
		dp[i] += dp[i - 1];
	}	
}

struct comp {
	bool operator()(pair<string, Long> a, pair<string, Long> b) {
		if (a.ss == b.ss) return a.ff < b.ff;
		return a.ss > b.ss;
	}
};

double dis(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double area(double a, double b, double c) {
	double p = a + b + c;
	p /= 2.0;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	forn (i, n) {
		cin >> v[i].ff >> v[i].ss;
	}
	
	double ans = 1000000000;
	double total = 0;
	
	for (int i = 2; i < n; i++) {
		double a = dis(v[0].ff, v[0].ss, v[i - 1].ff, v[i - 1].ss);
		double b = dis(v[0].ff, v[0].ss, v[i].ff, v[i].ss);
		double c = dis(v[i - 1].ff, v[i - 1].ss, v[i].ff, v[i].ss);
		total += area(a, b, c);

	}
	//debug(total);
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		double cur = 0;
		for (int j = i + 2; cnt < n; cnt++, j++) {
			int jj = (j%n);
			double a = dis(v[i].ff, v[i].ss, v[(jj - 1 + n)%n].ff, v[(jj - 1 + n)%n].ss);
			double b = dis(v[i].ff, v[i].ss, v[jj].ff, v[jj].ss);
			double c = dis(v[(jj - 1 + n)%n].ff, v[(jj - 1 + n)%n].ss, v[jj].ff, v[jj].ss);
			cur += area(a, b, c);
			//debug(cur);
			double res = total - cur;
			ans = min(ans, abs(res - cur));
		}
	}
	cout << prec(1) << ans << "\n";
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