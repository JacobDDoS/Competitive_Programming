#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, d; cin >> n >> d;
    int c = d;
    if (c&1) c++;
    cout << c/2 + (4*n-2 == d) << endl;
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