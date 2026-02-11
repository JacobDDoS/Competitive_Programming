#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    long long ans;
    vector<long long> nums(n), prefix(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        prefix[i] = nums[i] + (i != 0 ? prefix[i-1] : 0);
    }
    long long temp = 0;
    for (int i=1;i<n;i++) {
        temp -= nums[i];
    }
    ans = temp;
    long long absSum = 0;
    temp = nums[0];
    for (int i=1;i<n;i++) {
        temp = nums[0] + absSum - (prefix[n-1] - prefix[i]);
        ans = max(ans, temp);
        absSum += abs(nums[i]);
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