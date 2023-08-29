#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i=0;i<n;i++) {
        if (s[i] != t[i] && !((s[i]=='o'&&t[i]=='0')||(s[i]=='0'&&t[i]=='o')) && !((s[i]=='l'&&t[i]=='1')||(s[i]=='1'&&t[i]=='l'))) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}