#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    for (int a=1;a<=998;a++) {
        for (int b=1;b<=a;b++) {
            int c = 1000 - a - b;
            if (c*c == a*a + b*b) {
                cout << "The Pythagorean triplet for which a+b+c=1000 occurs when a = " << a << ", b = " << b << ", c = " << c << " which has a product of " << a*b*c << endl;
                return 0;
            }
        }
    }
}