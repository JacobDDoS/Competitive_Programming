#include <bits/stdc++.h>

using namespace std;

// 1 - 1
// 2 - 4
// 3 - 10
// 4 - 22
// 5 - 46

void solve() {
    int n; cin >> n;
    // 1111 0000 0000 0000 0000 - 2 operations
    // 1111 1111 1100 0000 0000 - 1
    // 1111 1111 1111 1111 1111 - 1

    // 1000 0000 0000 0000 0001

    if (n==1) {
        cout << "1\n";
        return;
    } else if (n<=4) {
        cout << "2\n";
        return;
    } else {
        int cur = 4;
        int ans = 2;

        while (n > cur) {
            ans++;
            cur += cur + 2;
        }
        cout << ans << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}