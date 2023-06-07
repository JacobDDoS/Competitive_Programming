// Author: JacobDDoS 
// Date: 6/7/23
// Problem: A. Politics

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    vector<string> o(n);
    vector<bool> m(n, true);
    for (int i=0;i<n;i++) {
        cin >> o[i];
    }
    for (int i=0;i<k;i++) {
        char c = o[0][i];
        for (int j=1;j<n;j++) {
            if (o[j][i] != c) {
                m[j] = false;
            }
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        if (m[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}