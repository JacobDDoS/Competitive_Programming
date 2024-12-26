#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    if (s.size()==1) {
        cout << "-1\n";
        return;
    } 

    for (int i=1;i<s.size();i++) {
        if (s[i-1] == s[i]) {
            cout << s.substr(i-1,2) << '\n';
            return;
        }
        if (i != 1) {
            if (s[i-2] != s[i]) {
                cout << s.substr(i-2, 3) << '\n';
                return;
            }
        }
    }

    cout << "-1\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}