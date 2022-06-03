// Author: JacobDDoS 
// Date: 6/3/22
// Problem: A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int x; cin >> x;
    bool foundZ = false; bool foundO = false;
    int count = 0;
    int ans = 0;
    for (int i=0;i<32;i++) {
        if (x & (1<<i)) {
            count++;
        }
    }
    for (int i=0;i<32;i++) {
        if (x & (1<<i) && !foundO) {
            ans ^= 1<<i;
            foundO = true;
        } else if (!(x&(1<<i)) && !foundZ && count <= 1) {
            ans ^= 1<<i;
            foundZ = true;
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