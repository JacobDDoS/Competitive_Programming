#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

map<int, bool> isPrime;

bool isNumPrime(int n) {
    n = abs(n);
    if (isPrime.contains(n)) return isPrime[n];
    for (int i=2;i*i<=n;i++) {
        if (n % i == 0) {
            isPrime[n] = false;
            return false;
        }
    }
    isPrime[n] = true;
    return true;
}

int numberOfPrimes(int a, int b) {
    int ans = 0;
    for (int i=0;;i++) {
        int val = i*i + a*i + b;
        if (isNumPrime(val)) {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int maxPrimes = 0, curAns = 0;
    for (int a=-999;a<1000;a++) {
        for (int b=-1000;b<=1000;b++) {
            int p = numberOfPrimes(a, b);
            if (p > maxPrimes) {
                cout << "Found new best, a = " << a << ", b = " << b << " which gives " << p << " primes" << endl;
                maxPrimes = p;
                curAns = a*b;
            }
        }
    }
    cout << "The product of a, b that produces the most number of consequtive primes is " << curAns << endl;
}