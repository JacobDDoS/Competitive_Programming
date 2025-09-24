#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    cout << (n-1)/(k-1) + ((n-1)%(k-1) ? 1 : 0) << endl;
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