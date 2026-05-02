#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool isPrime(int n)
{
    for (int i=2;i*i<=n;i++) if (n % i == 0) return false;
    return true;
}

int main()
{
    ll sum = 0;
    for (int i=2;i<2'000'000;i++) {
        if (isPrime(i)) sum += i;
    }
    cout << "The sum of the primes less than 2 million is " << sum << endl;
}