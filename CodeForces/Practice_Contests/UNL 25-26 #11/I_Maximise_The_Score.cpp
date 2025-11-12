#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(2*n);
    for (int i=0;i<2*n;i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i=0;i<2*n;i+=2) {
        ans += nums[i];
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