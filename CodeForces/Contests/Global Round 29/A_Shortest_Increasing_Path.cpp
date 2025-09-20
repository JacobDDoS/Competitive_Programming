#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int x, y; cin >> x >> y;
    if (y > x) {
        cout << "2\n";
        return;
    }

    if (x >= 1+y+1 && y > 1) {
        cout << "3\n";
        return;
    }

    cout << "-1\n";
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