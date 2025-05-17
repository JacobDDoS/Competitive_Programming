#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long totalCells = n * min(b, (m - (b - 1)));

    long long nC = n, mC = min(b, (m - (b - 1)));
    int ans0 = 1;

    while (nC > 1)
    {
        ans0++;
        if (nC & 1)
            nC++;
        nC /= 2;
    }
    while (mC > 1)
    {
        ans0++;
        if (mC & 1)
            mC++;
        mC /= 2;
    }

    // if (totalCells > m * min(a, (n - (a - 1))))
    // {
    //     n = min(a, (n - (a - 1)));
    // }
    // else
    // {
    //     m = min(b, (m - (b - 1)));
    // }

    // 3,3 -> 1, 3 -> 1,2 -> 1,1

    n = min(a, (n - (a - 1)));

    int ans = 1;
    while (n > 1)
    {
        ans++;
        if (n & 1)
            n++;
        n /= 2;
    }
    while (m > 1)
    {
        ans++;
        if (m & 1)
            m++;
        m /= 2;
    }
    cout << min(ans0, ans) << '\n';
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