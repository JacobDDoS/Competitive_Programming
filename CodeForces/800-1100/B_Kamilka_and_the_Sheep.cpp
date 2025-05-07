#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    cout << nums[nums.size()-1] - nums[0] << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}