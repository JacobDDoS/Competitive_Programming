#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    string s; cin >> s;
    ll f = 0, se = 0;
    int i = 1;
    f = s[0]-'0';
    for (;i<s.size();i++) {
        if (s[i] == '0') {
            f *= 10;
        } else {
            break;
        }
    }
    
    for (;i<s.size();i++) {
        se*=10;
        se+=s[i]-'0';
    }

    if (f < se) {
        cout << f << " " << se << endl;
    } else {
        cout << "-1" << endl;
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