// Author: JacobDDoS 
// Date: 5/22/22
// Problem: A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    char c = s[n/2];
    int ans = 0;
    for (int i=n/2;i>=0;i--) {
        if (s[i] == c) {
            ans++;
        } else {
            break;
        }
    }

    for (int i=n/2+1;i<n;i++) {
        if (s[i] == c) {
            ans++;
        } else {
            break;
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