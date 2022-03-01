// Author: JacobDDoS 
// Date: 2/28/22
// Problem: https://codeforces.com/contest/1635/problem/B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int ans = 0;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    for (int i=1;i<n-1;i++) {
        if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
            ans++;
            if (i!=n-2) {
                nums[i+1] = max(nums[i], nums[i+2]);
            } else {
                nums[i+1] = nums[i];
            }
        }
    }
    cout << ans << '\n';
    for (int i=0;i<n;i++) {
        cout << nums[i] << " ";
    }
    cout << '\n';
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