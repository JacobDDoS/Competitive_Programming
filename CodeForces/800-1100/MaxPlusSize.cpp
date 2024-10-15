#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int a = 0, b = 0;
    for (int i=0;i<n;i+=2) {
        a = max(a, nums[i]);
    }
    for (int i=1;i<n;i+=2) {
        b = max(b, nums[i]);
    }

    cout << max(a+(n+1)/2, b+n/2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}