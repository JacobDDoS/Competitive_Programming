#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    // if (n == 2) {
    //     cout << "3\n";
    //     return;
    // }
    if (n%3==0) {
        ans += 2*(n/3);
        if (n % 2 == 0) {
            ans += (n/2);
        } else {
            ans += (n/2)+1;
        }
    } else if (n%3 == 1) {
        ans += 2*((n-1)/3);
        if (n % 2 == 0) {
            ans += (n/2)+1;
        } else {
            ans += (n/2)+2;
        }
    } else {
        ans += (((n/2)+1)/3);
        ans += n - (((n/2)+1)/3)*3;
        ans++;
        ans += (n-1)/2;
    }

    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while (t--) {
        solve();
    // }
}