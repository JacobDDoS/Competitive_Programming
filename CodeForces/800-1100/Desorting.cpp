// Author: JacobDDoS 
// Date: 7/27/23
// Problem: A. Desorting

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    ll ans = 99999999999;
    for (int i=1;i<n;i++) {
        ans = min(ans, nums[i]-nums[i-1]+1);
    }
    if (ans & 1) {
        ans++;
    }
    if (ans < 0) {
        ans=0;
    }

    cout << ans/2 << endl;
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