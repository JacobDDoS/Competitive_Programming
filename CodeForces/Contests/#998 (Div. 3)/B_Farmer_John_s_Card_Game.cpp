#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    bool flag = true;
    vector<pair<int, int>> p(n);
    vector<int> nums(m);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> nums[j];
        }
        sort(nums.begin(), nums.end());
        for (int j=1;j<m;j++) {
            if (nums[j]-nums[j-1] != n) {
                flag = false;
            }
        }
        p[i] = make_pair(nums[0], i+1);
    }

    if (flag) {
        sort(p.begin(), p.end());
        for (auto& i : p) {
            cout << i.second << " ";
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}