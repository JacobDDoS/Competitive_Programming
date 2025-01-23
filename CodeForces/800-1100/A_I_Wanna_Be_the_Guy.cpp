#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<bool> arr(n);
    int p; cin >> p;
    for (int i=0;i<p;i++) {
        int a; cin >> a;
        arr[a-1] = true;
    }
    int q; cin >> q;
    for (int i=0;i<q;i++) {
        int a; cin >> a;
        arr[a-1] = true;
    }

    for (int i=0;i<n;i++) {
        if (!arr[i]) {
            cout << "Oh, my keyboard!";
            return;
        }
    }
    cout << "I become the guy.";
}

int main() {
    // int t; cin >> t;
    // while (t--) {
        solve();
    // }
}