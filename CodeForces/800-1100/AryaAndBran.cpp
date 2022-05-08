// Author: JacobDDoS 
// Date: 5/7/22
// Problem: Arya and Bran

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    int candies[n];
    for (int i=0;i<n;i++) {
        cin >> candies[i];
    }
    int candiesGiven = 0;
    int candiesHeld = 0;
    for (int i=0;i<n;i++) {
        candiesHeld += candies[i];
        if (candiesHeld >= 8) {
            candiesGiven += 8;
            candiesHeld -=8;
        } else {
            candiesGiven += candiesHeld;
            candiesHeld = 0;
        }
        if (candiesGiven >= k) {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}