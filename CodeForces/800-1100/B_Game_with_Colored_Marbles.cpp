#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mp[nums[i]]++;
    }

    int score = 0;
    int cnt = 0;
    for (auto& pr : mp) {
        if (pr.second == 1) {
            cnt++;
        } else {
            score++;
        }
    }

    score += 2*(cnt%2 + cnt/2);

    cout << score << '\n';


}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}