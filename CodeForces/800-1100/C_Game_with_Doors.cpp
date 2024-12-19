#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;

    int leftEnd = max(l1, l2);
    int rightEnd = min(r1, r2);
    if (rightEnd - leftEnd < 0) {
        cout << "1\n";
    } else {
        int ans = rightEnd - leftEnd;
        if (l1 < leftEnd || l2 < leftEnd) {
            ans++;
        }
        if (r1 > rightEnd || r2 > rightEnd) {
            ans++;
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