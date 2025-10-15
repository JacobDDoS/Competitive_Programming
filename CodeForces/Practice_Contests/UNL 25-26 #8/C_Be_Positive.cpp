#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, neg=0, maxNeg=-9999999, ans = 0;cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
        if (v[i] < 0) {
            neg++;
            maxNeg = max(maxNeg, v[i]);
        } else if (v[i] == 0) {
            ans++;
        }
    }
    if (neg&1) {
        ans += abs(maxNeg)+1;
    }
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