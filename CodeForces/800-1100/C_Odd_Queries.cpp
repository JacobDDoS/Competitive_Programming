#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    vector<int> prefixSums(n+1);
    prefixSums[0] = 0;
    for (int i=1;i<=n;i++) {
        prefixSums[i] = nums[i-1] + prefixSums[i-1];
    }

    int l, r, k;
    for (int i=0;i<q;i++) {
        cin >> l >> r >> k;
        int sum = prefixSums[n] - prefixSums[r] + prefixSums[l-1] + (r-l+1)*k;
        if (sum & 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}