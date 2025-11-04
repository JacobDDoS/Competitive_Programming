#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c=='0') cnt++;
    }

    int ans = 0;
    for (int i=0;i<cnt;i++) {
        if (s[i] == '1') ans++;
    }
    cout << ans << endl;
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