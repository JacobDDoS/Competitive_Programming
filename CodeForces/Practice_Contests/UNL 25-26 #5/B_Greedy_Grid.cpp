#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    if ((n > 2 && m != 1) || (m > 2 && n != 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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