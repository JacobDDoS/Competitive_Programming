// Author: JacobDDoS 
// Date: 11/25/22
// Problem: B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    if (n&1) {
        for (int i=0;i<n;i++) {
            cout << "2 ";
        }
        cout << '\n';
    } else {
        for (int i=0;i<n-2;i++) {
            cout << "2 ";
        }

        cout << "1 3\n";
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