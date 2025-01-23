#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mp[nums[i]]++;
    }


    int noPr = 0;
    for (auto& pr : mp) {
        if (pr.second != 0 && abs(mp[k-pr.first] - pr.second) != 0) {
            // cout << "when: " << k-pr.first << " and " << pr.second << " adds: " << abs(mp[k-pr.first] - pr.second) << endl;
            noPr += abs(mp[k-pr.first] - pr.second);
            if (mp[k-pr.first] == 0) {
                noPr += abs(mp[k-pr.first] - pr.second);
            }
        }
    }

    noPr /= 2;

    int expect = n/2 - (noPr/2 + noPr%2);

    cout << expect << '\n';

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}