#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 1;
    if (k&1) {
        n -= k;
    }
    ans += n/(k-1) + (n % (k-1) == 0 ? 0 : 1);
    cout << ans << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}