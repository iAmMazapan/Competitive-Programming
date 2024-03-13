#include <bits/stdc++.h>
using namespace std;

//n = 5
int fac = 1;

void factorial(int n) { //modificar
	if (n == 1) return;
	fac *= n;
	return factorial(n - 1);
}

int f(int n) {
	if (n == 1) return 1;
	return n*f(n - 1);
}
vector<int> a(100);
vector<vector<int>> global;
int n;

//n = 5 ; n - 1 = 4;
void backtracking(int index, vector<int> &cur) {
	if (index == n) {
		global.emplace_back(cur);
		return;
	}
	cur.emplace_back(a[index]);
	backtracking(index + 1, cur);
	cur.pop_back();
	backtracking(index + 1, cur);
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> cur;
	backtracking(0, cur);
	
	for (auto u : global) {
		for (auto v: u) cout << v << " ";
		cout << "\n";
	}
	
	return 0;
}