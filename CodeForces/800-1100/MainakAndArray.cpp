// Author: JacobDDoS 
// Date: 8/10/23
// Problem: Mainak and Array

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, b=-9999, m=99999; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        b = max(b, nums[i]);
        m = min(m, nums[i]);
    }
    int pot = nums[n-1]-nums[0];
    for (int i=0;i<n-1;i++) {
        pot = max(pot, nums[i]-nums[i+1]);
    }

    cout << max({pot, b-nums[0], nums[n-1]-m}) << endl;
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