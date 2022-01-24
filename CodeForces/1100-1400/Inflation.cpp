// Author: JacobDDoS 
// Date: 1/24/22
// Problem: https://codeforces.com/problemset/problem/1476/B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    ll d = nums[0];
    ld mx = 0;
    for (int i=1;i<n;i++) {
        if (nums[i]*((ld)100/k) > d) {
            mx = max(mx, nums[i]*((ld)100/k)-d);
        }
        d+=nums[i];
    }
    if (mx - floor(mx) < 1e-9) {
        cout << (ll)floor(mx) << '\n';
        return;
    }
    cout << (ll)ceil(mx) << '\n';
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