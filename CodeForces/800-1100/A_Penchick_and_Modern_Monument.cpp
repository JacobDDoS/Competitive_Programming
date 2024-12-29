#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        mp[nums[i]]++;
    }

    pair<int, int> maxPr = make_pair(0,0);
    for (auto& pr : mp) {
        if (pr.second > maxPr.second) {
            maxPr = pr;
        }
    }

    cout << n - maxPr.second << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}