#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, a, b; cin >> n >> a >> b;
    if (n & 1) {
        if (((a&1) && (b&1)) || ((b&1) && b > a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if ((!(a&1) && !(b&1)) || (!(b&1) && b > a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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