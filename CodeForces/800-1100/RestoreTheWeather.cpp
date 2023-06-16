// Author: JacobDDoS 
// Date: 6/16/23
// Problem: B. Restore the Weather

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    for (int i=0;i<n;i++) {
        int deg;
        cin >> deg;
        a[i] = make_pair(deg, i);
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ans(n);
    for (int i=0;i<n;i++) {
        int idx = a[i].second;
        ans[idx] = b[i];
    }

    for (int i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';

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