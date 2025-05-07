#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    map<int, int> mp;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    mp[2] = 2;
    mp[0] = 3;
    mp[1] = 1;
    mp[3] = 1;
    mp[5] = 1;
    for (int i=0;i<n;i++) {
        int s = nums[i];
        mp[s]--;

        if (mp[2] <= 0 && mp[0] <= 0 && mp[1] <=0 && mp[3] <= 0 && mp[5] <= 0) {
            return i+1;
        }
    }

    return 0;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}