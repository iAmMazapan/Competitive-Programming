#include<bits/stdc++.h> 
using namespace std;

using Long = long long;
 
const int N = 1e6 + 10;
const int INF = 1e9 + 10;

int st[4*N], a[N];

void build(int idx, int l, int r) {
    if (l == r) st[idx] = a[l];    
    else {
        int mid = (l + r) >> 1;
        build(2*idx, l, mid);
        build(2*idx + 1, mid + 1, r);
        st[idx] = min(st[2*idx], st[2*idx + 1]);
        //Merge (combine) 
    }
}

int query(int idx, int l, int r, int i, int j) { //0 indexded and closed interval [i, j]
    if (r < i || l > j) return INF;
    if (l >= i && r <= j) return st[idx];

    int mid = (l + r) >> 1;
    int left = query(2*idx, l, mid, i, j);
    int right = query(2*idx + 1, mid + 1, r, i, j);
    return min(left, right);
}

void update(int idx, int l, int r, int pos, int value) {
    if (l == r) st[idx] = value;
    else {
        int mid = (l + r) >> 1;
        if (pos <= mid) update(2*idx, l, mid, pos, value);
        else update(2*idx + 1, mid + 1, r, pos, value);
        st[idx] = min(st[2*idx], st[2*idx + 1]);
    }
}

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     int n, m; cin >> n >> m;
     
     for (int i = 0; i < n; i++) cin >> a[i];
     build(1, 0, n - 1);    
     int q, index, value, l, r;
     while (m--) {
         cin >> q;
         if (q&1) {
             cin >> index >> value;
             update(1, 0, n - 1, index, value);
         }
         else {
             cin >> l >> r;
             cout << query(1, 0, n - 1, l, r - 1) << "\n";
         }
     }
    return 0;
} 