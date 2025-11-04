#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<string> v;
    int col = 0, row = 0;
    for (int i=0;i<n;i++) {
        string s; cin >> s;
        v.push_back(s);
        col += (count(s.begin(), s.end(), '1') & 1);
    }
    for (int i=0;i<m;i++) {
        int cur = 0;
        for (int r=0;r<n;r++) {
            cur ^= v[r][i]-'0';
        }
        row += cur;
    }

    cout << max(row, col) << endl;
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