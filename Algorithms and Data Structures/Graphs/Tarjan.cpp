#include <bits/stdc++.h> 
using namespace std;

const int N = 1e5;

vector<int> g[N], low(N), disc(N, -1), visited(N);
vector<int> component;
int timer = 1, componentCount = 0;

void tarjan(int u) {
    low[u] = disc[u] = timer++;
    component.emplace_back(u);
    visited[u] = 1;

    for (auto v : g[u]) {
        if (disc[v] == -1) tarjan(v);
        if (visited[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == disc[u]) {
        cout << "Component " << componentCount++ << "\n";
        while (true) {
            int v = component.back();
            component.pop_back();
            visited[v] = 0;
            cout << v << " ";
            if (u == v) break;
        }
        cout << "\n";
    }
}

int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (disc[i] == -1) {
            tarjan(i);
        }
    }

}

/*
sample input:
7 11
1 2
2 3
2 6 
2 7
3 4
4 3
5 3
5 6
6 5
7 6

sample output:
Component 0
4 3 
Component 1
5 6 
Component 2
7 2 1 
*/