#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, a, b, c; cin >> m >> a >> b >> c;
    int ans = 0;
    ans += min(m, a) + min(m, b) + min((2*m - min(m,a) - min(m, b)), c);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}