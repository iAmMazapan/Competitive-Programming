#include<bits/stdc++.h>

using namespace std;

struct TwoSat {
    int n;
    vector<vector<int>> g, gt;
    vector<int> comp, topological_order, answer;
    vector< bool> vis;

    TwoSat() {}
    TwoSat(int _n) {init(_n);}

    void init(int _n) {
        n = _n;
        g.assign(2*n, vector<int>());
        gt.assign(2*n, vector<int>());
        comp.resize(2*n);
        vis.resize(2*n);
        answer.resize(2*n);
    }

    void addEdge(int u, int v) {
        g[u].emplace_back(v);
        gt[v].emplace_back(u);
    }

    // At least one of them is true
    void addClauseOr(int u, bool nu, int v, bool nv) {
        addEdge(u + (nu? n : 0), v + (nv? 0 : n));
        addEdge(v + (nv? n : 0), u + (nu? 0 : n));
    }

    // Only one of them is true
    void addClauseXor(int u, bool nu, int v, bool nv) {
        addClauseOr(u, nu, v, nv);
        addClauseOr(u, !nu, v, !nv);
    }

    // Both of them have the same value
    void addClauseAnd(int u, int nu, int v, int nv) {
        addClauseXor(u, !nu, v, nv);
    }

    void dfs(int u) {
        vis[u] = true;
        for (const auto &v : g[u]) 
            if (!vis[v]) dfs(v);
        topological_order.emplace_back(u);
    }

    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;
        for (const auto &v : gt[u]) 
            if (!vis[v]) scc(v, id);
    }

    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);
        for (int i = 0; i < 2*n; i++) if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;

        for (const auto &v : topological_order) {
            if (!vis[v]) scc(v, id++);
        }

        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n]? 1 : 0);
        }
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    TwoSat ts = TwoSat(m);

    for (int i = 0; i < n; i++) {
        int a, b;
        char ba, bb;
        cin >> ba >> a >> bb >> b;
        ts.addClauseOr(a - 1, (ba == '+'? true : false), b - 1, (bb == '+'? true : false));
    }

    if (ts.satisfiable()) {
        for (int i = 0; i < m; i++) cout << (ts.answer[i]? '+' : '-') << " "; 
    }
    else {
        cout << "IMPOSSIBLE";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tt = 1; cin >> tt;

    while (tt--) {
        solve();
    }

}