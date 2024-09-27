#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> mp;

void solve() {
    string n; cin >> n;
    ll ans = 1;
    for (int i=0;i<n.size();i++) {
        ans *= mp[(n[i]-'0')];
    }

    cout << ans << endl;
    
}

int main() {
    for (int i=0;i<=9;i++) {
        mp[i] = (int)((double)(i+2)/2*(i+1));
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}