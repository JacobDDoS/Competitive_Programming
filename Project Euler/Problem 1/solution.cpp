#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int sum = 0;
    for (int i=1;i<1000;i++) {
        if (i%3==0 || i%5==0) sum += i;
    }
    cout << "The sum of all the multiples of 3 or 5 under 1000 is " << sum << endl;
}

int main()
{
    solve();
}