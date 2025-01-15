#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if ((a+b+c)%2 == 1) {
        cout << "-1\n";
        return;
    }

    vector<int> nums = {a,b,c};
    sort(nums.begin(), nums.end());

    int dif = nums[0] + nums[1] - nums[2];

    int ans = 0;
    if (dif > 0) {
        ans += dif/2;
        ans += nums[2];
    } else {
        ans = nums[0] + nums[1];
    }
    
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}