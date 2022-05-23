// Author: JacobDDoS 
// Date: 5/21/22
// Problem: Digit Minimization

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s = to_string(n);
    if (s.size() == 1) {
        cout << s[0] << endl;
    } else if (s.size() == 2) {
        cout << s[1] << endl;
    } else {
        int sm=s[0];
        for (int i=0;i<s.size();i++) {
            if (s[i]-'0' < sm) {
                sm = s[i]-'0';
            }
        }
        cout << sm << endl;
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