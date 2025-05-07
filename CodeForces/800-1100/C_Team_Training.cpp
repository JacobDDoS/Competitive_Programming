#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    long long curSize = 1;
    for (int i=nums.size()-1;i>=0;i--) {
        if (curSize * nums[i] >= x) {
            ans++;
            curSize = 0;
        }
        curSize++;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}