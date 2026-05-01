#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    ll num = 600851475143;
    int largestPrime = 1;
    int p = 2;
    while (num > 1) {
        while (num % p == 0) {
            largestPrime = p;
            num /= p;
        }
        p++;
    }

    cout << "The largest prime of " << num << " is " << largestPrime << endl;
}

int main()
{
    solve();
}