#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> vs(n);
    for (int i=0;i<n;i++) {
        cin >> vs[i];
    }

    int ans = 0;
    for (int i=0;i<n;i++) {
        m -= vs[i].size();
        if (m >= 0) {
            ans++;
        } else {
            break;
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