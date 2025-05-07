#include <bits/stdc++.h>
using namespace std;

void solve2(vector<int>& v, vector<int>& queries, unordered_map<int, bool>& m) {
    int count = 0;
    for (int q : queries) {
        if (m.count(q)) {
            count += 2;
        } else {
            count ++;
        }
    }
    cout << count << ' ';
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = false;
    }
    vector<int> queries;
    while(n--) {
        int q; cin >> q;
        queries.push_back(q);
        for (int qu : queries) {
            m.erase(v[qu - 1]);
        }
        solve2(v, queries, m);
    }
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}