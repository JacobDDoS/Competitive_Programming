// Author: JacobDDoS 
// Date: 11/20/22

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

map<int, int> mp;

int solveArr(vector<int>& nums) {

    for (auto& pr : mp) {
        if (pr.second == 1) {
            return nums.size();
        }
    }
    for (int i=0;i<nums.size();i++) {
        if (nums[(nums.size()+i-1)%nums.size()] != nums[(i+1)%nums.size()]) {
            mp[nums[i]]--;
            nums.erase(nums.begin()+i);
            return 1 + solveArr(nums);
        }
    }

    mp[nums[0]]--;
    mp[nums[1]]--;
    nums.erase(nums.begin());
    nums.erase(nums.begin());
    return 1 + solveArr(nums);
}

void solve() {
    mp.clear();
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mp[nums[i]]++;
    }

    int ans = solveArr(nums);

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