#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD 1'000'000'007

ll exponentiate(ll x, ll p, map<ll, ll>& expMp) {
    ll result = 0;
    if (expMp[p] != 0) return expMp[p];
    if (!(p&1)) {
        result = exponentiate(x, p/2, expMp) * exponentiate(x, p/2, expMp) % MOD;
    }
    else {
        result = x * exponentiate(x, p-1, expMp) % MOD;
    }
    expMp[p] = result;
    return result;
}

ll power(ll x, ll p) {
    map<ll, ll> mp;
    mp[0] = 1;
    mp[1] = x;
    return exponentiate(x, p, mp);
}

int main() {
    ll n; cin >> n;
    cout << power(2, n) << endl;
}