#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    bool flag = false;
    int idx = -1;

    for (int i=0;i<n;i++) {
        bool tempFlag = true;
        for (int j=0;j<n;j++) {
            if (i != j && abs(nums[i]-nums[j]) % k == 0) {
                tempFlag = false;
            }
        }
        if (tempFlag) {
            idx = i+1;
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << "YES\n";
        cout << idx << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}