// Author: JacobDDoS 
// Date: 9/3/22
// Problem: 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    ll sum = 0;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    for (int i=0;i<n;i++) {
        nums[i] = sum/(n-i);
        sum -= nums[i];
    }

    unordered_map<int, int> mp;
    mp.reserve(50001);
    for (int i=0;i<n;i++) {
        mp[nums[i]]++;
    }

    ll ans = 0;
    if (mp.size() == 1) {
        cout << 0 << '\n';
    } else {
        for (pair<int, int> pr : mp) {
            if (!ans) {
                ans = pr.second;
            } else {
                ans *= pr.second;
            }
        }
        cout << ans << '\n';
    }

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