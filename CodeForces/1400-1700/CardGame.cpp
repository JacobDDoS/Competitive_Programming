#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    ll ans = 0;
    for (int i=2;i<n;i++) {
        if (nums[i] > 0) {
            ans += nums[i];
        }
    }
    if (n>=2 && (nums[0] + nums[1] > 0 && nums[0]+nums[1] > nums[0])) {
        ans += nums[0] + nums[1];
    } else if (nums[0] > 0) {
        ans += nums[0];
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*
1. Take all the positive odd ones first 
2. See if the second index is worth taking
    If it is:
        Take the first index, then the rest of the positive numbers, and then it
    If it is not:
        Remove it, then take the rest of the positive numbers
*/