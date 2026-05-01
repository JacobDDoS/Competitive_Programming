#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int totalSquareNumbers = 688000/2;
    ll sum = 0;
    for (ll i=0;i<totalSquareNumbers;i++) {
        sum += (i*2+1) * (i*2+1);
    }
    cout << "the sum of the first " << totalSquareNumbers << " which are odd is " << sum << endl;
}

int main()
{
    solve();
}