#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << abs(nums[0]-nums[nums.size()-1]) + abs(nums[1]-nums[nums.size()-1]) + abs(nums[1]-nums[nums.size()-2]) + abs(nums[nums.size()-2]-nums[0]) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}