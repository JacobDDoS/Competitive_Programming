// Author: JacobDDoS 
// Date: 11/20/22

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (n == a && a == b) {
        cout << "YES\n";
        return;
    }
    if (n-2-a-b >= 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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