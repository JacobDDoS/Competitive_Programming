#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a1, a2, a4, a5; cin >> a1 >> a2 >> a4 >> a5;
    int ans1 = 1;
    if (a4 == (a1+a2)+a2) {
        ans1++;
    }

    if (a5 == (a4)+(a1+a2)) {
        ans1++;
    }


    int ans2 = 0;
    int a3 = a4-a2;
    if (a3 == a2+a1) {
        ans2++;
    }
    if (a4 == a3+a2) {
        ans2++;
    }
    if (a5 == a4+a3) {
        ans2++;
    }

    cout << max(ans1, ans2) << '\n';
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}