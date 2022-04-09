// Author: JacobDDoS 
// Date: 4/9/22
// Problem: https://codeforces.com/problemset/problem/1471/A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, x; cin >> n >> x;
    ll sum = 0;
    ll max = 0;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        sum += a;
        max += a/x + ((a%x)?1:0);
    }
    cout << (sum/x + ((sum%x) ? 1 : 0));
    cout << " " << max << '\n';
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