#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, a; cin >> n >> a;
    int cnt = 0;
    for (int i=0;i<n;i++) {
        int num; cin >> num;
        if (num > a) cnt++;
        else if (num < a) cnt--;
    }
    if (cnt >= 0) cout << a + 1 << '\n';
    else cout << a - 1 << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}