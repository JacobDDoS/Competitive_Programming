// Author: JacobDDoS 
// Date: 8/13/22
// Problem: C

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

map<int, vector<int>> posi;

void setToZero(vector<int>& nums, int num) {
    for (int& pos : posi[num]) {
        nums[pos] = 0;
    }
}

void solve() {
    posi.clear();
    int n; cin >> n;
    vector<int> nums(n);
    
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        posi[nums[i]].push_back(i);
    }
    set<int> numsSoFar;
    int ans = 0;
    numsSoFar.insert(nums[0]);
    for (int i=1;i<n;i++) {
        if (nums[i] < nums[i-1]) {
            ans += numsSoFar.size();
            for (int num : numsSoFar) {
                setToZero(nums, num);
            }
            numsSoFar.clear();
        }
        if (nums[i] != 0) {
            numsSoFar.insert(nums[i]);
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