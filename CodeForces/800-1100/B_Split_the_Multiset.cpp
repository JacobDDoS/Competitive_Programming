#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if ((n-1)%(k-1)==0) {
        cout << (n-1)/(k-1) << '\n';
    } else {
        cout << (n-1)/(k-1) + 1 << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}