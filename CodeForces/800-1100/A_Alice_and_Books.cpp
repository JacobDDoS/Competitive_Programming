#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int maxP = nums[0];
    for (int i=0;i<n-1;i++) {
        maxP = max(maxP, nums[i]);
    }

    cout << maxP + nums[nums.size()-1] << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}