#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
const long long INF = 1e18;

vector<long long> d(N ,INF);
vector<int> vis(N);
vector<pair<int, long long>> g[N];

void solve() {
    int n, m; cin >> n >> m;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        long long c; cin >> c;
        g[a].emplace_back(b, c);
    }

    pq.push({0, 1});
    d[1] = 0;

    while (!pq.empty()) {
        auto [cdist, node] = pq.top(); pq.pop();
        if (cdist > d[node]) continue;

        for (auto [v, w] : g[node]) {
            if (d[node] + w < d[v]) {
                d[v] = d[node] + w;
                pq.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tt = 1; //cin >> tt;

    while (tt--) {
        solve();
    }

}