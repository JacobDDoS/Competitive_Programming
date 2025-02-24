#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n&1) {
        cout << "Kosuke\n";
    } else {
        cout << "Sakurako\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}