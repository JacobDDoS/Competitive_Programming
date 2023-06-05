// Author: JacobDDoS 
// Date: 6/3/23
// Problem: A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i=0;i<n;i++) {
        if (i % k == 0 || i == n-1) {
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