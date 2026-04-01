#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    bool flag = true;
    for (int i=1;i<s.size();i++) {
        if (s[i] != s[0]) flag = false;
    }
    if (flag || (s >= rev && k==0)) cout << "NO\n";
    else cout << "YES\n";
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