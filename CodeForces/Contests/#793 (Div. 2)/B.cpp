// Author: JacobDDoS 
// Date: 5/22/22
// Problem: B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int ans = -1;
    for (int i=0;i<n;i++) {
        int c; cin >> c; 
        if (c != i) {
            if (ans==-1) {ans=c;continue;}
            ans &= c;
        }
    }
    cout << ans << '\n';
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