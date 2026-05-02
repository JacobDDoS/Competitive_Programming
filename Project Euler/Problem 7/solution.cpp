#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool isPrime(int n) {
    for (int i=2;i*i<=n;i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main()
{
    int p = 0;
    for (int i=2;;i++) {
        p += isPrime(i);
        if (p == 10001) {
            cout << "The 10001th prime is " << i << endl;
            break;
        }
    }
}