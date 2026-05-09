#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

int digitCount(int n) {
    if (n >= 100'000) return 6;
    if (n >= 10'000) return 5;
    if (n >= 1'000) return 4;
    if (n >= 100) return 3;
    if (n >= 10) return 2;
    if (n >= 1) return 1;
    return 0;
}

void rotate(int& num) {
    int lastDigit = num % 10;
    num /= 10;
    num += pow(10, digitCount(num)) * lastDigit;
}

bool isPrime(int num) {
    for (int i=2;i*i<=num;i++) {
        if (num%i==0) return false;
    }
    return true;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int ans = 0;
    for (int i=2;i<1'000'000;i++) {
        if (isPrime(i)) {
            bool flag = true;
            int copy = i;
            rotate(copy);
            while (copy != i) {
                if (!isPrime(copy)) {
                    flag = false;
                    break;
                }
                rotate(copy);
            }
            ans += flag;
        }
    }
    cout << "The number of circular primes below a million is " << ans << endl;
}