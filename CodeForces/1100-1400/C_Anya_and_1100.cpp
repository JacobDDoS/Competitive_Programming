#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int q; cin >> q;

    if (s.size() < 4) {
        for (int i=0;i<q;i++) {
            int a, b; cin >> a >> b;
            cout << "NO\n";
        }
        return;
    }

    vector<bool> posi(s.size()-3);
    set<int> setIdx;
    for (int i=3;i<s.size();i++) {
        if (s.substr(i-3, 4) == "1100") {
            posi[i-3] = true;
            setIdx.insert(i-3);
        }
    }

    for (int i=0;i<q;i++) {
        int a; cin >> a;
        char b; cin >> b;
        s[a-1] = b;
        for (int j=a-1;j<min((int)s.size(), a+3);j++) {
            if (j-3 >= 0) {
                if (s.substr(j-3, 4) == "1100") {
                    posi[j-3] = true;
                    setIdx.insert(j-3);
                } else if (posi[j-3]) {
                    posi[j-3] = false;
                    setIdx.erase(j-3);
                }
            }
        }
        if (setIdx.size()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}