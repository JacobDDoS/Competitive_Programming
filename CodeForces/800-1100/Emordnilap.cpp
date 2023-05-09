// Author: JacobDDoS 
// Date: 5/5/23
// Problem: Emordnilap

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

ull const mod = 1000000007;

void solve() {
    ll n; cin >> n;
    ull s = (n*(n-1));
    ull f = 1;
    for (ll i=2;i<=n;i++) {
        f *= i;
        f %= mod;
    }

    cout << (s*f)%mod << '\n';
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