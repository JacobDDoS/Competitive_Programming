#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) if (a[i] <= i+1) ans++;
    cout << ans << '\n';
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