#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());


    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for (int i=1;i<=n;i++) {
        prefix[i] = nums[i-1] + prefix[i-1];
    }

    int x, y; 
    for (int i=0;i<q;i++) {
        cin >> x >> y;
        cout << prefix[x] - prefix[x-y] << '\n';
    }
}

int main() {
    // int t; cin >> t;
    // while (t--) {
        solve();
    // }
}