#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0, cur = n;
    while (k > 0) {
        ans++;
        if (cur == n) {
            k-=cur;
            cur--;
        } else {
            k-=cur;
            if (k > 0) {
                ans++;
                k-=cur;
            }
            cur--;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}