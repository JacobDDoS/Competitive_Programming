// Author: JacobDDoS 
// Date: 1/1/2022
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=572

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, q;
    cin >> n >> q;
    int hol[n+1], gue[n+1], jer[n+1];
    hol[0] = 0, gue[0] = 0, jer[0] = 0;
    for (int i=1;i<=n;i++) {
        int cow; cin >> cow;
        hol[i] = hol[i-1];
        gue[i] = gue[i-1];
        jer[i] = jer[i-1];
        if (cow == 1) {
            hol[i]++;
        } else if (cow == 2) {
            gue[i]++;
        } else {
            jer[i]++;
        }
    }
    for (int i=0;i<q;i++) {
        int low, high; cin >> low >> high;
        cout << hol[high] - hol[low-1] << " " << gue[high] - gue[low-1] << " " << jer[high] - jer[low-1] << "\n";
    }
}

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}