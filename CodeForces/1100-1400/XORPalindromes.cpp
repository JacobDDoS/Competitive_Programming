#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = 0, u = 0, hasMiddle=((s.size()%2) == 1);
    for (int i=0;i<s.size()/2;i++) {
        if (s[i] == s[s.size()-1-i]) {
            m++;
        } else {
            u++;
        }
    }

    string ans = "";
    for (int k=0;k<=n;k++) {
        int i = k;
        if (i==u) {
            ans.push_back('1');
        }
        else if (i>u) {
            i -= u;
            if (i%2==1 && hasMiddle==1) {
                i--;
            }
            if (i % 2 == 0 && i/2 <= m) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
        } else {
            ans.push_back('0');
        }
    }
    cout << ans << endl;
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