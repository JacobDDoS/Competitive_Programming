// Author: JacobDDoS 
// Date: 8/31/22
// Problem: Divide and Multiply

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

    ll greatestOddNumber = 1;
    ll twos = 1;
    for (int i=0;i<n;i++) {
        while (!(nums[i] & 1) && nums[i] > 0) {
            twos *= 2;
            nums[i]/=2;
        }
        if (nums[i] & 1 && nums[i] > 0) {
            greatestOddNumber = max(greatestOddNumber, nums[i]);
        }
    }

    for (int i=0;i<n;i++) {
        if (nums[i] == greatestOddNumber) {
            nums[i] *= twos;
            break;
        }
    }

    ll ans = 0;
    for (int i=0;i<n;i++) {
        ans += nums[i];
    }

    cout << ans << '\n';

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