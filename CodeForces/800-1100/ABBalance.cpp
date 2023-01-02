// Author: JacobDDoS 
// Date: 1/1/23
// Problem: AB Balance

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    string s; cin >> s;
    int ab = 0, ba = 0;
    bool isA = s[0] == 'a';
    for (int i=0;i<s.size();i++) {
        if (isA && s[i] == 'a') {
            continue;
        } else if (isA) {
            ab++;
            isA = false;
        } else if (!isA & s[i] == 'b') {
            continue;
        } else if (!isA) {
            ba++;
            isA = true;
        }
    }

    if (ab != ba) {
        s[s.size()-1] = s[s.size()-1]=='a' ? 'b' : 'a';
    }

    cout << s << '\n';

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