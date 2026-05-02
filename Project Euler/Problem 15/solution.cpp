#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

map<ll, ll> mp;

ll numberOfRoutes(ll r, ll c) {
    ll key = (r<<32) | c;
    if (mp[key]) return mp[key];

    ll ans = 0;
    if (r != 1) ans += numberOfRoutes(r-1, c);
    if (c != 1) ans += numberOfRoutes(r, c-1);
    mp[key] = ans;
    return ans;

}

int main()
{
    ll k = (1ll << 32) | 1;
    mp[k] = 1;
    cout << "There are " << numberOfRoutes(20+1, 20+1) << " routes in a 20x20 grid" << endl;
}