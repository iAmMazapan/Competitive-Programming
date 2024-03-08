#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"

const int N = 1e6;
const int INF = 1e9;
using Long = long long;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    
	Long n; cin >> n;
	
	while (n != 1) {
		cout << n << " ";
		if (n&1) (n *= 3) += 1;
		else n	 >>= 1;
	}
	cout << 1;
	
    return 0;
}