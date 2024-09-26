#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, x; cin >> n >> x;
    vector<ll> a(n), s(n+1);
    s[0] = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }

    ll ans = 0;
    map<int, int> dp;
    auto ptrEnd = lower_bound(s.begin(), s.end(), x+s[0]+1);
    int add = (ptrEnd-s.begin())-1;
    ans += add;
    dp[add+1]++;
    // cout << "first add: " << add << endl;
    // cout << "added: " << 1 << " to " << add+2 << endl;
    for (int i=1;i<n;i++) {
        ptrEnd = lower_bound(ptrEnd, s.end(), x+s[i]+1);

        int add = (ptrEnd-s.begin())-1-i;
        ans += add * (1 + dp[i]);
        dp[i+add+1]+= 1 + dp[i];

        // cout << "added: " << 1 << " to " << add+2 << endl;
        // cout << "add: " << add << endl;
        // cout << "extra: " << add*dp[i] << endl;
    }

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}