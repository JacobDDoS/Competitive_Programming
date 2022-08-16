// Author: JacobDDoS 
// Date: 8/15/22
// Problem: B. Also Try Minecraft

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> cols(n);
    for (ll i=0;i<n;i++) {
        cin >> cols[i];
    }
    vector<ll> right(n);
    vector<ll> left(n);

    ll s = 0;
    for (ll i=1;i<n;i++) {
        if (cols[i-1] > cols[i]) {
            s += cols[i-1] - cols[i];
        } 
        right[i] = s;
    }
    right[0] = 0;

    s = 0;
    for (ll i=n-2;i>=0;i--) {
        if (cols[i] < cols[i+1]) {
            s -= cols[i] - cols[i+1];
        } 
        left[i] = s;
    }

    left[n-1] = 0;

    for (ll i=0;i<m;i++) {
        ll f, l; cin >> f >> l;
        if (f < l) {
            cout << right[l-1]-right[f-1] << '\n';
        } else {
            cout << left[l-1] - left[f-1] << '\n';
        }
    }

}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}