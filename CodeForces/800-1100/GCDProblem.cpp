// Author: JacobDDoS 
// Date: 12/29/22
// Problem: B. GCD Problem

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

int gcd(int a, int b) {
    if (b==0) {
        return a;
    } else if (b < 2) {
        return b;
    } else {
        return gcd(b, a%b);
    }
}

void solve() {
    int n; cin >> n;
    for (int i=2;i<n;i++) {
        if (gcd((n-i-1), i) == 1) {
            cout << n-i-1 << " " << i << " " << 1 << '\n';
            break;
        }
    }
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