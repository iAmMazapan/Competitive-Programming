#include<bits/stdc++.h>
using namespace std;
 
long long ans = 0;
 
void merge(vector<int> &a, int l, int r) {
	vector<int> temp(r - l + 1);
	int mid = (l + r)/2;
	int i = l, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) temp[k++] = a[i++];
		else {
			temp[k++] = a[j++];
			ans += (mid - i + 1);
		}
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= r) temp[k++] = a[j++];
	for (i = l; i <= r; i++) a[i] = temp[i - l];	
}
 
void merge_sort(vector<int> &a, int l, int r) {
	if (l < r) {
		int mid = (l + r)/2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, r);
	}
}
 
int main() {
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<pair<int, int>> a(n);
		vector<int> order;
		for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
		sort(a.begin(), a.end());
		
		for (int i = 0; i < n; i++) order.emplace_back(a[i].second);
		
		merge_sort(order, 0, n - 1);
		cout << ans << "\n";
		ans = 0; 	 
	}
	return 0;
}