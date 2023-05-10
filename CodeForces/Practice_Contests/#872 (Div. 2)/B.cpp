// Author: JacobDDoS 
// Date: 5/9/23
// Problem: LuoTianyi and the Table

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> nums(n*m);
    for (int i=0;i<n*m;i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    ll ans = (nums[nums.size()-1]-nums[0])*n*(m-1) + (nums[nums.size()-1]-nums[1])*(n-1);
    ll ans1 = (nums[nums.size()-1]-nums[0])*m*(n-1) + (nums[nums.size()-1]-nums[1])*(m-1);
    ll ans2 = (nums[nums.size()-1]-nums[0])*n*(m-1) + (nums[nums.size()-2]-nums[0])*(n-1);
    ll ans3 = (nums[nums.size()-1]-nums[0])*m*(n-1) + (nums[nums.size()-2]-nums[0])*(m-1);

    cout << max({ans, ans1, ans2, ans3}) << '\n';
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