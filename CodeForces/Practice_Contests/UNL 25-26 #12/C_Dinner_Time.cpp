#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m, p, q; cin >> n >> m >> p >> q;
    int r = n - p*(n/p);

    if (r == 0 && (n/p)*q != m) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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