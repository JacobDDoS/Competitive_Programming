#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r, k; cin >> l >> r >> k;
    cout << max(r/k - l + 1,0) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}