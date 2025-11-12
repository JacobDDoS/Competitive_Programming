#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int ans = (s[0] == '@');
    for (int i=1;i<n;i++) {
        if (s[i-1] == '*' && s[i] == '*') {
            cout << ans << endl;
            return;
        }
        if (s[i] == '@') ans++;
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