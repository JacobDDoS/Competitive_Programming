// Author: JacobDDoS 
// Date: 8/10/23
// Problem: B. Ugo

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int firstOne = -1, ans=0;

    for (int i=0;i<n;i++) {
        if (s[i]=='1') {
            break;
        } else if (i == n-1) {
            cout << "0\n";
            return;
        }
    }
    
    for (int i=0;i<n;i++) {
        if (s[i]=='1') {
            firstOne=i;
            break;
        }
    }

    for (int i=firstOne;i<n;i++) {
        if (ans&1 && s[i] == '1') {
            ans++;
            firstOne=s[i];
        } else if (!(ans&1)&&s[i]=='0') {
            ans++;
            firstOne=s[i];
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