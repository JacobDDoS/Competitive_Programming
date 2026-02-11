#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    string a, b, c; cin >> a >> b >> c;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, INT_MAX));
    dp[0][0] = 0;
    for (int i=0;i<=a.size();i++) {
        for (int j=0;j<=b.size();j++) {
            int aIdx = i-1, bIdx = j-1;
            if (i != 0) {
                dp[i][j] = dp[i-1][j] + (c[aIdx + bIdx + 1] == a[aIdx] ? 0 : 1);
            }

            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + (c[aIdx + bIdx + 1] == b[bIdx] ? 0 : 1));
            }
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
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