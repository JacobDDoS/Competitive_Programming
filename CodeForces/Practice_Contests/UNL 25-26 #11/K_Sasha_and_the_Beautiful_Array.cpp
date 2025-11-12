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
    int ans = 0;
    for (int i=1;i<n;i++) {
        ans += nums[i] - nums[i-1];
    }
    cout << ans << endl;
    
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