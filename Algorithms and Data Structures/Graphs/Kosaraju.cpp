#include <bits/stdc++.h>
using namespace std;

using Long = long long;
const Long MOD = 1e9 + 7;
const int N = 1e5 + 10;

#define debug(x) cout << #x << " = " << x << "\n"

vector<int> g[N], gt[N], visited(N);
vector<int> order, component;

void dfs1(int u) {
    visited[u] = 1;
    for (auto v : g[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.emplace_back(u);
}

void dfs2(int u) {
    visited[u] = 1;
    component.emplace_back(u);
    for (auto v : gt[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n, m; cin >> n >> m;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].emplace_back(b);
        gt[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }
    for (int i = 1; i <= n; i++) visited[i] = 0;

    reverse(order.begin(), order.end());
    int cnt = 1;

    for (auto u : order) {
        if (!visited[u]) {
            dfs2(u);
            cout << "Component #" << cnt++ << ":\n";
            for (auto v : component) cout << v << " ";
            cout << "\n";
            component.clear();
        }
    }

    return 0;
}

/*
    OUTPUT:
    Component #1:
    6 8 7 
    Component #2:
    5 
    Component #3:
    4 
    Component #4:
    1 2 3 
*/