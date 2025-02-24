#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n+1);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n+1;i++) {
        cin >> b[i];
    }

    int maxEver = a[0];
    int dist = abs(b[n]-a[0]);
    long long ans = 0;
    for (int i=0;i<n;i++) {
        if (abs(b[n] - a[i]) < dist) {
            maxEver = a[i];
            dist = abs(b[n]-a[i]);
        }
        if (abs(b[n]-b[i]) < dist) {
            maxEver = b[i];
            dist = abs(b[n]-b[i]);
        }

        if ((b[n] >= a[i] && b[n] <= b[i]) || (b[n] <= a[i] && b[n] >= b[i])) {
            maxEver = b[n];
            dist = 0;
        }

        ans += abs(b[i]-a[i]);
    }
    ans++;
    ans += abs(maxEver-b[n]);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}