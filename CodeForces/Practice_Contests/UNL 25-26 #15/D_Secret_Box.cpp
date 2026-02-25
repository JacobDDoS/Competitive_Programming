#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll bestFactor(ll k, ll a, ll b) {
    ll ans = 0;
    for (int i=1;i<=max((ll)ceil(sqrt((double)k)), a);i++) {
        if (k % i == 0 && k/i <= b) {
            ans = max(ans, (a-i+1) * (b-k/i+1));
        }
    }
    return ans;
}

void solve()
{
    ll x, y, z, k; cin >> x >> y >> z >> k;
    unordered_map<ll, vector<int>> mp;
    vector<ll> factors, dims = {x, y, z};
    ll maxVal = ceil(sqrt(k));
    sort(dims.begin(), dims.end());

    ll ans = 0;
    for (int i=1;i<=max(dims[0], maxVal);i++) {
        if (k % i == 0) {
            ans = max(ans, (dims[0]-i+1)*bestFactor(k/i, dims[1], dims[2]));
        }
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