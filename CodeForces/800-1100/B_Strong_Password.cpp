#include <bits/stdc++.h>

using namespace std;

string newChar(char c) {
    if (c == 'l') {
        return "w";
    }
    return "l";
}

void solve() {
    string s; cin >> s;
    for (int i=1;i<s.size();i++) {
        if (s[i-1] == s[i]) {
            s.insert(i, newChar(s[i]));
            cout << s << '\n';
            return;
        }
    }
    s.push_back(newChar(s[s.size()-1])[0]);
    cout << s << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}