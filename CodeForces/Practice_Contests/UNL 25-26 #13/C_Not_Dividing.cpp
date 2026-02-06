#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (nums[i] == 1) nums[i] = 2;
    }
    for (int i=0;i<n-1;i++) {
        while (nums[i+1] % nums[i] == 0) nums[i+1]++;
    }
    for (int a : nums) {
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