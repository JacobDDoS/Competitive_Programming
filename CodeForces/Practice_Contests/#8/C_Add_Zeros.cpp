#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    map<ll, bool> mp;
    mp[nums.size()] = true;
    set<pair<ll, ll>> st;
    for (int i=1;i<n;i++) {
        st.insert(make_pair(nums[i]+i, i+1));
    }

    ll ans = nums.size();
    while (st.size()) {
        pair<ll, ll> cur = (*st.begin());
        st.erase(st.begin());
        if (mp[cur.first]) {
            mp[cur.first+(cur.second-1)] = true;
            ans = max(ans, cur.first+(cur.second-1));
        }
    }

    cout << ans << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
