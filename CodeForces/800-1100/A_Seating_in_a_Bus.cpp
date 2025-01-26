#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool b[n + 2];
    for (int i=0;i<n+2;i++) {
        b[i] = false;
    }
    b[a[0]] = true;
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (!(b[(a[i] - 1)] || b[(a[i] + 1)])) {
            flag = false;
            break;
        }
        b[a[i]] = true;
    }
    cout << (flag ? "YES" : "NO") << '\n';
}
 
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}