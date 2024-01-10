#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    string s; cin >> s;
    int z=0, o=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='0') {
            z++;
        } else {
            o++;
        }
    }

    for (int i=0;i<s.size();i++) {
        if (s[i]=='0' && o) {
            o--;
        } else if (s[i]=='1'&&z) {
            z--;
        } else {
            cout << max(z, o) << endl;
            return;
        }
    }

    cout << "0\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}