#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, X; cin >> n >> X;
    vector<int> nums(n), order(n);
    for (int i=0;i<n;i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    long long current = 0;
    long long ans = 0;
    int l=0,r=n-1,o=0;
    while (r >= l) {
        if ((current+nums[r])/X > current/X) {
            order[o] = nums[r];
            o++;
            ans += nums[r];
            current += nums[r--];
        } else {
            order[o] = nums[l];
            o++;
            current += nums[l++];
        }
    }
    cout << ans << '\n';
    for (int a : order) {
        cout << a << " ";
    }
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