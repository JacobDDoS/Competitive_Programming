#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInversePrime(long long a, long long p) {
    return power(a, p - 2, p);
}


void solve()
{
    
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