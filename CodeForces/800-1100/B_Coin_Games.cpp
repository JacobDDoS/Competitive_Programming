#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='U') {
            cnt++;
        }
    }

    cout << (cnt % 2 == 0 ? "NO" : "YES") << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}