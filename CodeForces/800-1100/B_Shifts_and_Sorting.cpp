#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    long long ans = 0;
    int zeroPtr = 0, onePtr = 0;
    while (zeroPtr < s.size() && onePtr < s.size()) {
        while (onePtr < s.size() && s[onePtr] != '1') {
            onePtr++;
        }

        while ((zeroPtr < s.size() && s[zeroPtr] != '0') || zeroPtr < onePtr) {
            zeroPtr++;
        }

        if (zeroPtr >= s.size() || onePtr >= s.size()) {
            break;
        }

        // cout << "onePtr: " << onePtr << " zero: " << zeroPtr << endl;
        ans += zeroPtr - onePtr + 1;
        s[onePtr] = '0';
        s[zeroPtr] = '1';
        onePtr++;
        zeroPtr++;
    }

    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}