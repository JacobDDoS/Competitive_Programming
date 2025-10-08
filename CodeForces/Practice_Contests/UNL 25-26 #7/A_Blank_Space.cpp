#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int ans = 0, cur = 0;
    int n; cin >> n;

    for (int i=0;i<n;i++) {
        int a; cin >> a;
        if (a == 1) {
            ans = max(ans, cur);
            cur = 0;
        } else {
            cur++;
        }
    }
    ans = max(ans, cur);
    cout << ans << endl;
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