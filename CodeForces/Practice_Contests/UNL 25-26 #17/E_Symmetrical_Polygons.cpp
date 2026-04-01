#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> v(n), u;
    for (int i=0;i<n;i++) cin >> v[i];
    
    map<ll, ll> mp;
    for (int i : v) mp[i]++;

    ll numPairs = 0, side = 0;
    for (auto& pr : mp) {
        if (pr.second > 1) {
            numPairs += pr.second / 2;
            side += pr.first * (pr.second / 2);
        }
        if (pr.second & 1) {
            u.push_back(pr.first);
        }
    }

    sort(u.begin(), u.end());
    ll ans = 0;
    if (numPairs >= 2) {
        ans = side * 2;
    }

    // try two
    for (int i=u.size()-1;i>=1;i--) {
        double a = (double)u[i-1], b = (double)u[i];
        if ((double)side > abs(a-b)/2.0 && !(abs(side - (abs(a-b)/2.0)) < 1e-5)) {
            ans = side * 2 + a + b;
            break;
        }
    }

    // try one 
    for (int i=u.size()-1;i>=0;i--) {
        double a = (double)u[i];
        if (side > a/2.0) {
            ans = max(ans, side*2 + u[i]);
            break;
        }
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