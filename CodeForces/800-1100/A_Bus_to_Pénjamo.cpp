#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> families(n);
    for (int i=0;i<n;i++) {
        cin >> families[i];
    }

    int ans = 0, loners = 0;
    for (int i=0;i<n;i++) {
        ans += (families[i]/2)*2;
        loners += (families[i]&1);
    }

    ans += min(loners, (m*2-ans)-loners);
    cout << ans << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}