#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int i=0;
    // cout << "HELLO";
    for (;i<n-1;i++) {
        if (min(nums[i], nums[i+1]) != 0) {
            long long minVal = min(nums[i], nums[i+1]);
            nums[i] -= minVal;
            nums[i+1] -= minVal;
        }
    }

    for (int i=0;i<n-1;i++) {
        if (nums[i+1] < nums[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}