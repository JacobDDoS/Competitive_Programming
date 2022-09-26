// Author: JacobDDoS 
// Date: 9/16/22
// Problem: Dreamoon and Ranking Collection

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, x; cin >> n >> x;
    set<int> a;
    for (int i=0;i<n;i++) {
        int t; cin >> t;
        a.insert(t);
    }

    int v = 0;
    while (true) {
        v++;
        if (!a.count(v)) {
            if (!x) {
                v--;
                break;
            }
            x--;
        } 
    }

    cout << v << '\n';

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