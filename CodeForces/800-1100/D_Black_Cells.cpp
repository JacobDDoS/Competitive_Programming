#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    long long ans = 1;
    for (int i=1;i<n;i+=2) {
        ans = max(ans, nums[i]-nums[i-1]);
    }

    vector<long long> dif;
    if (n&1) {
        long long tempAns = 1e18;
        long long tempMax = 1;
        for (int i=0;i<n;i+=2) {
            tempMax = 1;
            for (int j=1;j<n;j+=2) {
                if (j == i+1) {
                    j++;
                }

                tempMax = max(tempMax, nums[j]-nums[j-1]);
            }
            tempAns = min(tempAns, tempMax);
        }
        ans = min(ans, tempAns);
    }

    cout << ans << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}