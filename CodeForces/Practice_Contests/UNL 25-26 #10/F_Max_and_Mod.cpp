#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    if (!(n&1)) {
        cout << "-1" << endl;
        return;
    }

    cout << n << " ";
    for (int i=1;i<=n-1;i++) {
        cout << i << " ";
    }
    cout << endl;
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