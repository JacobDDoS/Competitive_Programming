#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int ans = INT_MAX;
    for (int i=1;i<=10;i++) {
        ans = min(ans, abs(x1-i)+abs(x2-i)+abs(x3-i));
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}