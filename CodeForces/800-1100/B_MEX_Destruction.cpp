#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        if (nums[i] != 0) {
            while (nums[i] != 0 && i < n) {
                i++;
            }
            ans++;
        }
    }
    cout << min(ans, 2) << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}