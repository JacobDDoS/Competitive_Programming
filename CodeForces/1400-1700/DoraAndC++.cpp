#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll a, b; cin >> a >> b;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    ll greatestCommonDivisor = gcd(a, b);
    
    for (int i=0;i<n;i++) {
        nums[i] %= greatestCommonDivisor; 
    }

    sort(nums.begin(),nums.end());
    // for (int i=0;i<n;i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    ll largestBreak = nums[0]+1;

    for (int i=0;i<n;i++) {
        if (i == n-1) {
            largestBreak = max(largestBreak, greatestCommonDivisor-nums[i]);
        } else {
            largestBreak = max(largestBreak, nums[i+1]-nums[i]);
        }
    }

    cout << greatestCommonDivisor - largestBreak << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}