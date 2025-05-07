#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 1;
    map<int, vector<int>> mp;
    vector<pair<int, int>> edges;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }
    vector<pair<int, int>> vOfAmt;
    for (auto& pr : mp) {
        vOfAmt.push_back(make_pair(pr.second.size(), pr.first));
    }
    sort(vOfAmt.begin(), vOfAmt.end());
    reverse(vOfAmt.begin(), vOfAmt.end());

    // cout << vOfAmt[0].first << ": " << vOfAmt[0].second << endl;
    if (vOfAmt[0].first == 2 && n >= 5) {
        cout << "3\n" << endl;
        return;
    }
    for (auto& edge : mp[vOfAmt[0].second]) {
        mp[edge].pop_back();
    }
    mp[vOfAmt[0].second].clear();
    ans = vOfAmt[0].first;

    int firstOne = vOfAmt[0].second;

    vOfAmt.clear();
    for (auto& pr : mp) {
        vOfAmt.push_back(make_pair(pr.second.size(), pr.first));
    }
    sort(vOfAmt.begin(), vOfAmt.end());
    reverse(vOfAmt.begin(), vOfAmt.end());

    // cout << vOfAmt[0].first << ": " << vOfAmt[0].second << endl;
    ans += vOfAmt[0].first - 1;



    int otherAns = 0;
    if (n <= 2) {
        cout << ans << '\n';
        return;
    }

    mp.clear();
    vOfAmt.clear();
    for (int i=0;i<n-1;i++) {
        int a, b; 
        a = edges[i].first;
        b = edges[i].second;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for (auto& pr : mp) {
        vOfAmt.push_back(make_pair(pr.second.size(), pr.first));
    }
    sort(vOfAmt.begin(), vOfAmt.end());
    reverse(vOfAmt.begin(), vOfAmt.end());

    // cout << vOfAmt[1].first << ": " << vOfAmt[1].second << endl;
    for (auto& edge : mp[vOfAmt[1].second]) {
        mp[edge].pop_back();
    }
    mp[vOfAmt[1].second].clear();
    otherAns = vOfAmt[1].first;

    vOfAmt.clear();
    for (auto& pr : mp) {
        vOfAmt.push_back(make_pair(pr.second.size(), pr.first));
    }
    sort(vOfAmt.begin(), vOfAmt.end());
    reverse(vOfAmt.begin(), vOfAmt.end());

    int i = 0;
    while (vOfAmt[i].second == firstOne) {
        i++;
    }

    // cout << vOfAmt[i].first << ": " << vOfAmt[i].second << endl;
    otherAns += vOfAmt[i].first - 1;

    cout << max(ans, otherAns) << '\n';
    
}

int main() {
    int t;
    t = 2;
    t = 3;
    
    cin >> t;
    while (t--) {
        solve();
    }
}