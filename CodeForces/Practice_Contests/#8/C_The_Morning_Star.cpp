#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<long long, long long>> v(n);
    unordered_map<long long, long long> col, row, leftDag, rightDag;
    col.reserve(n*2);
    row.reserve(n*2);
    leftDag.reserve(n*2);
    rightDag.reserve(n*2);
    
    for (int i=0;i<n;i++) {
        long long a, b; cin >> a >> b;
        v[i] = make_pair(a, b);
        col[a]++;
        row[b]++;
        leftDag[a-b]++;
        rightDag[a+b]++;
    }

    long long ans = 0;
    for (auto& pr : col) {
        if (pr.second > 1) {
            ans += pr.second*(pr.second-1);
        }
    }
    for (auto& pr : row) {
        if (pr.second > 1) {
            ans += pr.second*(pr.second-1);
        }
    }
    for (auto& pr : leftDag) {
        if (pr.second > 1) {
            ans += pr.second*(pr.second-1);
        }
    }
    for (auto& pr : rightDag) {
        if (pr.second > 1) {
            ans += pr.second*(pr.second-1);
        }
    }

    cout << ans << '\n';
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}