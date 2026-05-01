#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool valid(int n)
{
    for (int i=2;i<=20;i++) {
        if (n % i != 0) return false;
    }
    return true;
}

int main()
{
    auto start = chrono::steady_clock::now();
    for (int i=1;;i++) {
        if (valid(i)) {
            auto timeSinceStart = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-start);
            cout << "Naive (" << timeSinceStart.count() << "ms)" << ": Smallest positive number divisible by 1 through 20 is " << i << endl;
            break;
        }
    }

    start = chrono::steady_clock::now();
    ll cur = 1;
    for (int i=2;i<=20;i++) {
        cur *= i / gcd(i, cur);
    }
    auto timeSinceStart = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-start);
    cout << "LCM-GCD Formula (" << timeSinceStart.count() << "ms): Smallest positive number divisible by 1 through 20 is " << cur << endl; 
}