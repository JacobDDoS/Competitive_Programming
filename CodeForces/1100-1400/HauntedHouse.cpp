#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<ll> ones;
    set<ll> zeros;
    for (int i=0;i<s.size();i++) {
        if (s[i] == '0') {
            zeros.insert(s.size()-i-1);
        } else {
            ones.insert(s.size()-i-1);
        }
    }

    ll ans = 0;
    for (int i=1;i<=n;i++) {
        auto onesItr = ones.begin();    
        auto zerosItr = zeros.begin();

        if (zeros.size()==0) {
            cout << "-1 ";
            continue;
        }
        if (ones.size() > 0 && *onesItr < *zerosItr) {
            int o = *onesItr, z = *zerosItr;
            ans += z-o;
            ones.erase(onesItr);
            zeros.erase(zerosItr);

            ones.insert(z);
            cout << ans << " ";
        } else {
            zeros.erase(zerosItr);
            cout << ans << " ";
        }
    }
    cout << endl;
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