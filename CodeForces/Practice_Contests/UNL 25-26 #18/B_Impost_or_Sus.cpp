#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    string s; cin >> s;
    int ans = 0;
    if (s[0] != 's') ans++;
    if (s[s.size()-1] != 's') ans++;
    for (int i=1;i<s.size()-2;i++) {
        if (s[i] == 'u' && s[i+1] == 'u') {
            s[i+1] = 's';
            ans++;
        }
    }
    cout << ans << '\n';
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