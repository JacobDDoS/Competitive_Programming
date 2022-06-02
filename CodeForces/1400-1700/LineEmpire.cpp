// Author: JacobDDoS 
// Date: 6/2/22
// Problem: Line Empire

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    vector<int> nums(n);
    vector<int> dif(n);
    cin >> nums[0]; 
    ll sum = nums[0];
    dif[0] = nums[0];

    for (int i=1;i<n;i++) {
        cin >> nums[i];
        sum += nums[i];
        dif[i] = nums[i] - nums[i-1];
        // cout << "dif[" << i << "]: " << dif[i];
    }

    ll curSum = 0;
    ll curB = 0;
    ll ans = sum * b;
    for (int i=0;i<n;i++) {
        curSum += nums[i];
        curB += dif[i];
        ans = min(ans, nums[i]*a + (curB + (sum-curSum - (n-(i+1))*nums[i]))*b);
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