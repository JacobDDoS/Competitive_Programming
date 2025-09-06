#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    long long sum = 0;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
        mp[nums[i]]++;
    }

    for (int k = nums.size() - 1; k >= 0; k--)
    {
        sum += nums[k];
        if (mp.size() && mp.rbegin()->first > nums[k])
        {
            sum += mp.rbegin()->first - nums[k];
        }
        cout << sum << " ";
        if (mp.size() && mp.rbegin()->first > nums[k])
        {
            sum -= mp.rbegin()->first - nums[k];
        }

        if (mp[nums[k]] > 1)
        {
            mp[nums[k]]--;
        }
        else if (mp[nums[k]] == 1)
        {
            mp.erase(nums[k]);
        }
    }

    cout << endl;
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