#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    for (int i=0;i<n-1;i++) {
        if (min(nums[i], nums[i+1])*2 > max(nums[i], nums[i+1])) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}