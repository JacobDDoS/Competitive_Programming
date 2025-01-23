#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int andded = nums[0];
    for (int i=1;i<n;i++) {
        andded &= nums[i];
    }
    if (andded > 0) {
        cout << "1\n";
        return;
    }

    int ans = 0;
    int curAnd = nums[0];
    for (int i=0;i<n;i++) {
        curAnd &= nums[i];
        if (curAnd == 0) {
            ans++;
            if (i != n-1) {
                curAnd = nums[i+1];
            }
        }
    }


    cout << max(1, ans) << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}