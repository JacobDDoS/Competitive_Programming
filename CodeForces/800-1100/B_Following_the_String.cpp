#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    map<int, vector<char>> mp;
    for (char i='a';i<='z';i++) {
        mp[0].push_back(i);
    }
    string ans = "";
    for (int i=0;i<n;i++) {
        char a = mp[nums[i]][mp[nums[i]].size()-1];
        mp[nums[i]].pop_back();
        mp[nums[i]+1].push_back(a);
        ans.push_back(a);
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}