#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, num;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans += num;
        if (num == 0)
        {
            ans++;
        }
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