#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    int n = r-l;
    double prev = ((1.0+sqrt(1+8*(double)n))/2);
    int ans = (int)prev;
    // cout << "prev: " << prev;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}