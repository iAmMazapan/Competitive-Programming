#include <bits/stdc++.h>
using namespace std;

using Long = long long;
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define debug(x) cout << #x << " = " << x << "\n"
#define sz(v) ((Long)(v).size())
#define ff first
#define ss second
#define prec(n) fixed << setprecision(n)

const int INF = 1e9;
const int N = 1e6 + 5;


struct MinStack{
	stack<pair<int, int>> st;
	int getMin() {return st.top().second;}
	void push(int val) {
		if (st.empty()) st.push({val, val});
		else st.push({val, min(val, getMin())});
		
	}
	void pop() {st.pop();}
};

struct minQueue{
	stack<pair<int, int>> s1, s2;
	
	int size() {return s1.size() + s2.size();}
	bool isEmpty() {return size() == 0;}
	
	int getMin() {
		if (isEmpty()) return INF;
		if (!s1.empty() && !s2.empty()) {
			return min(s1.top().second, s2.top().second);
		}
		if (!s1.empty()) return s1.top().second;
		return s2.top().second;
	}
	
	void push(int val) {
		if (s2.empty()) s2.push({val, val});
		else s2.push({val, min(val, s2.top().second)});
	}
	
	void pop() {
		if (s1.empty()) {
			while (!s2.empty()) {
				int x = s2.top().first;
				int mini = s1.empty()? x : min(x, s1.top().second);
				s1.push({x, mini}); 
				s2.pop();
			}
		}
		assert(!s1.empty());
		s1.pop();
	}
	
};

int main() {
	int n; cin >> n;
	int x;
	minQueue q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
	
	while (!q.isEmpty()) {
		cout << q.getMin() << "\n";
		q.pop();
	}
}