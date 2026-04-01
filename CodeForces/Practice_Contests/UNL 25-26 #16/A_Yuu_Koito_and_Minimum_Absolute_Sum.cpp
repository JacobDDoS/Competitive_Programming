#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    bool f = false, l = false;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (i == 0 && nums[i] == -1) f = true;
        if (i == n-1 && nums[i] == -1) l = true;
        if (nums[i] == -1) nums[i] = 0;
    }

    int val = 0;
    for (int i=1;i<n;i++) val += (nums[i]-nums[i-1]);

    if (val < 0 && l) {
        nums[n-1] = -val;
        val = 0;
    } else if (val > 0 && f) {
        nums[0] = val;
        val = 0;
    }
    
    cout << abs(val) << '\n';
    for (int num : nums) cout << num << " ";
    cout << '\n';
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