#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    int ex = 0, target = sum/n;
    for (int i=0;i<n;i++) {
        if (nums[i] + ex < target) {
            cout << "NO\n";
            return;
        } else if (nums[i] >= target) {
            ex += nums[i]-target;
        } else {
            ex -= (target-nums[i]);
        }
    }
    cout << "YES\n";
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