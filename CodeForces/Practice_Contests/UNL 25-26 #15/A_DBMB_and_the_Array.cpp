#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, x, s; cin >> n >> s >> x;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        s-=a;
    }
    if (s >= 0 && s % x == 0) {cout << "YES\n";}
    else {cout << "NO\n";}
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