#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    map<int, int> mp;
    for (int i=0;i<n;i++) {
        mp[nums[i]]++;
    }

    int ans = mp.size();

    vector<pair<int,int>> vp;
    for (auto& pr : mp) {
        vp.push_back(make_pair(pr.second, pr.first));
    }

    sort(vp.begin(), vp.end());
    int cnt = 0;
    for (int i=0;i<vp.size();i++) {
        if (cnt+vp[i].first <= k) {
            ans--;
            cnt += vp[i].first;
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