#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int numFactors(int n) {
    int ans = 2;
    for (int i=2;i*i<=n;i++) {
        if (n%i == 0) ans += 2;
    }
    return ans;
}

int main()
{
    int cur = 0;
    for (int i=1;;i++) {
        cur += i;
        if (numFactors(cur) > 500) {
            cout << "The first triangle number to have over 500 factors is " << cur << ", located after adding up to and including " << i << endl;
            return 0;
        }
    }
}