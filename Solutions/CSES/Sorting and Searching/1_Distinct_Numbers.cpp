#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x <<"\n"

const int N = 1e6;
const int INF = 1e9;
using Long = long long;

int main() {
	set<int> s;
	int x, n; cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	
	cout << s.size();
	return 0;
}