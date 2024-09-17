#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(int head, map<int, set<int>>& mp) {
    int x;
    vector<int> toRemove;
    for (int elm : mp[head]) {
        cout << "? " << head << " " << elm << endl;
        cin >> x;
        if (x==head) continue;
        toRemove.push_back(elm);
        mp[x].insert(elm);
    }

    for (int elm : toRemove) {
        mp[head].erase(elm);
    }

    for (int elm : mp[head]) {
        dfs(elm, mp);
    }
}

void solve() {
    int n; cin >> n;
    map<int, set<int>> mp;
    for (int i=2;i<=n;i++) {
        mp[1].insert(i);
    }
    dfs(1, mp);

    cout << "!";
    for (int i=1;i<=n;i++) {
        for (int elm : mp[i]) {
            cout << " " << i << " " << elm;
        }
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

