#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n; cin >> n;
    vector<long long> nums(n);
    long long evenSum = 0, oddSum = 0;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (i & 1) {
            oddSum += nums[i];
        } else {
            evenSum += nums[i];
        }
    }

    cout << ((oddSum/(n/2) == evenSum/((n+1)/2) && oddSum % (n/2) == 0 && evenSum % ((n+1)/2) == 0) ? "YES" : "NO") << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}