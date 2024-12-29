#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s, r; cin >> s >> r;
    int sZ = 0, sO = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='1') {
            sO++;
        } else {
            sZ++;
        }
    }

    for (int i=0;i<n-1;i++) {
        if (r[i] == '0') {
            if (sO && sZ) {
                sO--;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            if (sZ && sO) {
                sZ--;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    if (sO + sZ == 1 && sO >= 0 && sZ >= 0) {
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