// Author: JacobDDoS 
// Date: 6/16/23
// Problem: Karina And Array (B)

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << max(a[0]*a[1], a[a.size()-1]*a[a.size()-2]) << '\n';
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