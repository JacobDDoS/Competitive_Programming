#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<bool> v(n, false);
    for (int i=n-2;i>=0;i--) {
        int j = i;
        while (j <= n-2 && s[j] == 'A' && s[j+1] == 'B' && !v[j]) {
            ans++;
            s[j] = 'B';
            s[j+1] = 'A';
            v[j] = true;
            j++;
        }
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