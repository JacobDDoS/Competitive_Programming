#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    long long x1,x2,x3,y1,y2,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ans = 1;

    if ((x1-x2)*(x1-x3) > 0) {
        ans += min(abs(x1-x2), abs(x1-x3));
    }

    if ((y1-y2)*(y1-y3) > 0) {
        ans += min(abs(y1-y2), abs(y1-y3));
    }
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