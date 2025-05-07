#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, a; cin >> x >> y >> a;
    a %= (x+y);
    if (a < x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}