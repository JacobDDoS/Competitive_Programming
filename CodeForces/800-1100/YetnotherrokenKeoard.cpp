#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    string s; cin >> s; 
    int l=0, u=0;
    string ansB="";
    for (int i=s.size()-1;i>=0;i--) {
        if (s[i] == 'b') {
            l++; 
        } else if (s[i] == 'B') {
            u++;
        } else if (isupper(s[i])) {
            if (u) {
                u--;
            } else {
                ansB.push_back(s[i]);
            }
        } else {
            if (l) {
                l--;
            } else {
                ansB.push_back(s[i]);
            }
        }
    }


    string ans="";
    for (int i=ansB.size()-1;i>=0;i--) {
        ans.push_back(ansB[i]);
    }
    cout << ans[ans.size()] << '\n';
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