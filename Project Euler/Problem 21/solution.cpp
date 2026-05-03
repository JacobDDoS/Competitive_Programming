#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int d(int n) {
    int ans = 1;
    for (int i=2;i*i<=n;i++) {
        if (n % i == 0) {
            ans += i;
            if (i*i!=n) ans += n/i;
        }
    }
    return ans;
}

int main()
{
    int ans = 0;
    for (int i=2;i<10000;i++) {
        int pr = d(i);
        if (pr >= 2 && d(pr) == i && pr != i) {
            ans += i;
            // cout << "found amicable number: " << i << " d(i): " << d(i) << ", d(pr): " << d(pr) << endl;
        }
    }
    cout << "The sum of amicable numbers under 10000 is " << ans << endl;
}