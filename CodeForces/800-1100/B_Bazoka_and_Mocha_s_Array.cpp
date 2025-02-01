#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    int cnt = 0;
    for (int i=1;i<n;i++) {
        if (nums[i-1] > nums[i]) {
            while (i < n) {
                if (nums[i-1] > nums[i]) {
                    cnt++;
                }
                if (nums[i] > nums[0] || cnt >= 2) {
                    cout << "NO\n";
                    return;
                }
                i++;
            }
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