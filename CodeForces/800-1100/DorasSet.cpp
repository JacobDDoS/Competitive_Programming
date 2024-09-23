#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (!(a&1)) {
        a++;
    } 
    if (!(b&1)) {
        b--;
    }

    int ans = 0, q = b-a;
    if (q >= 2) {
        ans++;
        q -= 2;
        ans += q / 4;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}