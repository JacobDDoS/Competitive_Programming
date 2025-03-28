#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, y; cin >> n >> x >> y;
    long long sum = 0, ans = 0;
    vector<long long> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums.begin(), nums.end());
    for (int i=0;i<n;i++) {
        long long atMost = sum-x - nums[i];
        long long atLeast = sum-y - nums[i];
        ans -= distance(upper_bound(nums.begin(), nums.begin()+i, atMost), lower_bound(nums.begin(), nums.begin()+i, atLeast));
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}