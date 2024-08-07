#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << "= " << x << "\n"

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;
    while (l < r) {
        int mid1 = l + (r - l)/3;
        int mid2 = r - (r - l)/3;

        if (a[mid1] < a[mid2]) {
            l = mid1 + 1;
        }
        else {
            r = mid2 - 1;
        }
    }
    //maximum at index l
    debug(a[l]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int tt = 1; //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}