#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int lengthOfChain(ll n) {
    int ans = 0;
    while (n != 1) {
        if (n&1) {
            n *= 3;
            n++;
        } else {
            n /= 2;
        }
        ans++;
    }
    return ans;
}

int main()
{
    ll ans = 1, length = 0;
    for (ll i=1;i<1'000'000;i++) {
        ll temp = lengthOfChain(i);
        if (temp > length) {
            length = temp;
            ans = i;
        }
    }
    cout << "The starting number with the longest chain under 1,000,000 is " << ans << " with a chain length of " << lengthOfChain(ans) << endl;
}