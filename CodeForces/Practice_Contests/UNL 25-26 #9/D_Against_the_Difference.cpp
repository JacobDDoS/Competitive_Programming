#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n), dp(n, 0);
    for (int i=0;i<n;i++) cin >> nums[i];

    unordered_map<int, deque<int>> mp;
    for (int i=0;i<n;i++) {
        if (nums[i] == 1) {
            dp[i] = (i != 0 ? dp[i-1] : 0) + 1;
        } else if (mp[nums[i]].size() == nums[i]-1) {
            int firstPosition = mp[nums[i]].front();
            dp[i] = max(dp[i-1], (firstPosition != 0 ? dp[firstPosition-1] : 0) + nums[i]);
            mp[nums[i]].pop_front();
        }

        if (dp[i] == 0 && i != 0) dp[i] = dp[i-1];
        mp[nums[i]].push_back(i);
    }

    cout << dp[n-1] << endl;
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