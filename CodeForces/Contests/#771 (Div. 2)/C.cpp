// Author: JacobDDoS 
// Date: 2/14/22
 
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;
 
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    set<int> co;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    int max=nums[0];
    co.insert(nums[0]);
    for (int i=1;i<nums.size();i++) {
        if (nums[i] > max) {
            max = nums[i];
            co.insert(nums[i]);
        } else {
            auto coGreater = co.lower_bound(nums[i]);
            vector<int> toErase;
            if (coGreater != co.end()) {
                co.erase(coGreater, (--co.end()));
                // for (auto it=coGreater;it!=(--co.end());it++) {
                //     toErase.push_back((*it));
                // }
                // for (int& elm : toErase) {
                //     co.erase(elm);
                // }
            }
        }
    }
    cout << co.size() << '\n';
}
 
int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    //solve();
}