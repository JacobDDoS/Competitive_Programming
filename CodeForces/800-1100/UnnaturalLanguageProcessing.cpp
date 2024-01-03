#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<int> idx;
    for (int i=s.size()-1;i>=0;i--) {
        if (s[i] == 'c' || s[i] == 'b' || s[i] == 'd') {
            i-=2;
            idx.insert(i);
        } else {
            i-=1;
            idx.insert(i);
        }
    }

    string ans = "";
    for (int i=0;i<n;i++) {
        if (idx.count(i) && i != 0) {
            ans.push_back('.');
        } 
        ans.push_back(s[i]);
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