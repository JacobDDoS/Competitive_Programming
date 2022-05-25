// Author: JacobDDoS 
// Date: 2/25/22
// Problem: B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    int curLarge = -1;
    int ans = 0;
    for (int i=0;i<n;i++) {
        if (curLarge == -1) {
            curLarge=nums[i];
        } else {
            if (nums[i] < curLarge) {
                ans++;
                curLarge = -1;
            } else {
                curLarge = nums[i];
            }
        }
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