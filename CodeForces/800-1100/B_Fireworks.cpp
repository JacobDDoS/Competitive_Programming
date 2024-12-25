#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, m; cin >> a >> b >> m;
    long long ans = 2;
    ans += (m/a) + (m/b);

    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}