#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    ll a, b, k; cin >> a >> b >> k;
    if ((a/gcd(a,b)) <= k && (b/gcd(a,b)) <= k) cout << "1\n";
    else cout << "2\n";
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