#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int cnt = 0, ans = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='0') {
            cnt++;
        } else {
            cnt = 0;
        }

        if (cnt == m) {
            ans++;
            for (int j=i;j<min(n, i+k);j++) {
                s[j] = '1';
            }
            cnt = 0;
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