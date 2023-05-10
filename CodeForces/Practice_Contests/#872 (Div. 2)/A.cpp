// Author: JacobDDoS 
// Date: 5/9/23
// Problem: LuoTianyi and the Palindrome String

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    string s; cin >> s;
    if (s.size() == 1) {
        cout << "-1\n";
        return;
    }
    for (int i=0;i<s.size()-1;i++) {
        if (s[i] != s[i+1]) {
            break;
        } else if (i == s.size()-2) {
            cout << "-1\n";
            return;
        }
    }
    cout << s.size()-1 << '\n';
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