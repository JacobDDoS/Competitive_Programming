#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    vector<int> v(3, 0);
    v[2] = 1;
    for (int i=3;;i++) {
        int res = v[i-2] + v[i-1];
        v.push_back(res);
        if (res > 4'000'000) break;
    }

    ll sum = 0;
    for (int num : v) if (!(num&1)) sum += num;
    cout << "The sum of even fibonacci numbers whose values do not exceed 4,000,000 is " << sum << endl;
}

int main()
{
    solve();
}