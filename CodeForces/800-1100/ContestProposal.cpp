#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }

    int maxNum = 0;
    for (int i=0;i<n;i++) {
        int dif = (lower_bound(b.begin(), b.end(), a[i]) - b.begin()) - i;
        maxNum = max(maxNum, dif);
    }

    cout << maxNum << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}