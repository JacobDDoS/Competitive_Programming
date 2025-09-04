#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    int lp = 0, rp = nums.size() - 1;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!flag)
            {
                cout << nums[lp] << " " << nums[rp] << " ";
            }
            else
            {
                cout << nums[rp] << " " << nums[lp] << " ";
            }
        }
        cout << '\n';
        if (flag)
        {
            lp++;
            rp--;
        }
        flag = !flag;
    }
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