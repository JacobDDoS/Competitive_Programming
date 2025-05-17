#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1] && nums[i] == 0)
        {
            cout << "YES\n";
            return;
        }
        if (nums[i] == 0)
        {
            flag = true;
        }
    }
    if (nums[nums.size() - 1] == 0)
    {
        flag = true;
    }
    if (flag)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    // 1 1 0 1 0 1
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