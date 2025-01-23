#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int xdif = m, ydif = m;
    int l, ll; cin >> l >> ll;
    for (int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        xdif += a;
        ydif += b;
    }

    cout << 2*(xdif+ydif) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}