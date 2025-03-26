#include<bits/stdc++.h>

using namespace std;


long long merge(vector<int> &a, int l, int r) {
    vector<int> temp(r - l + 1);
    int mid  =(l + r) >> 1;
    int i = l, j = mid + 1;
    int k = 0;
    long long inversions = 0;
    
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = temp[i - l];
    return inversions;
}

long long mergeSort(vector<int> &a, int l, int r) {
    int ans = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        ans += mergeSort(a, l, mid);
        ans += mergeSort(a, mid + 1, r);
        ans += merge(a, l, r);
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = mergeSort(a, 0, n - 1);
    cout << ans << "\n";
    for (auto u : a) cout << u << " ";
    cout << "\n";

    return 0;
}


/*
    8
    1 3 5 10 2 6 8 9
    number of inversions : 6

*/