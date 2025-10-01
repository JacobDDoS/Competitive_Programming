#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 1, cur = 1;
    while (cur < n) {
        cur *= 2;
        cur++;
        ans++;
    }
    cout << ans * 2 + 1 << endl;
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