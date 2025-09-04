#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (i != x)
        {
            cout << i << " ";
        }
        else
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << x << '\n';
    }
    else
    {
        cout << '\n';
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