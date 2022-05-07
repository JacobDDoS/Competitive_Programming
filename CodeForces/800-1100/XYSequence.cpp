// Author: JacobDDoS 
// Date: 5/6/22
// Problem: XY Sequence

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, b, x, y; cin >> n >> b >> x >> y;
    ll total = 0;
    int curVal = 0;
    while (n--) {
        if (curVal + x <= b) {
            curVal += x;
        } else {
            curVal -= y;
        }
        total += curVal;
    }
    cout << total << '\n';
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