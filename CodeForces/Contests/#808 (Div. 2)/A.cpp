// Author: JacobDDoS 
// Date: 7/16/22
// Problem: A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<n;i++) {
        if (a[i] % a[0] != 0) {
            cout << "NO\n";
            return;
        } 
    }
    cout << "YES\n";
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