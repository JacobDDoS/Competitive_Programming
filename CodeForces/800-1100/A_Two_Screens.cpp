#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int endPt = 0;
    for (int i=0;i<s.length();i++) {
        if (s[i]==t[i]) {
            endPt++;
        } else {
            break;
        }
    }
    cout << (s.length()+t.length()-endPt) + (endPt > 0 ? 1 : 0) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}