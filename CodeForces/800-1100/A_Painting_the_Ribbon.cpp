#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int minMax = (n/m) + (n%m == 0 ? 0 : 1);
    if (n - minMax > k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}