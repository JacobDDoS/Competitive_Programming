#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// 1 3 4 4 7
// 0 2 4 4 16
// 0 2 6 10 26
void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> cards(m, vector<int>(n, 0));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> cards[j][i];
        }
    }
    for (int i=0;i<cards.size();i++) {
        sort(cards[i].begin(), cards[i].end());
    }
    ll ans = 0;
    ll temp = 0;
    for (int i=0;i<m;i++) {
        temp = 0;
        for (long long j=0;j<n;j++) {
            if (j != 0) {
                temp += (j)*(cards[i][j] - cards[i][j-1]);
            }
            ans += temp;
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