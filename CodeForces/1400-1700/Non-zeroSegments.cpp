// Author: JacobDDoS 
// Date: 5/6/22
// Problem: Non-zero Segments

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int nums[n];
    int ans = 0;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    ll total = 0;
    map<ll, int> mp;
    for (int i=0;i<n;i++) {
        total += nums[i];
        mp[total]++; 
        if (total == 0 || mp[total] > 1) {
            ans++;
            total = nums[i];
            mp.clear();
            mp[total]++;
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}