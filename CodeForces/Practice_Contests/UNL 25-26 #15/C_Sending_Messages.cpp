#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    long long n, f, a, b; cin >> n >> f >> a >> b;
    vector<int> m(n+1, 0);
    for (int i=1;i<=n;i++) cin >> m[i];
    for (int i=0;i<n;i++) {
        f -= min(b, (m[i+1]-m[i])*a);
        if (f <= 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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