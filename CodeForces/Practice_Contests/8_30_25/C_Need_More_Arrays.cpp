#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int cur = nums[0], ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > cur + 1)
        {
            cur = nums[i];
            ans++;
        }
    }
    cout << ans << '\n';
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