#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    int win = n, los = 0, ans = 0;
    while (win > 1 || los > 1) {
        // cout << win << ", " << los << " + " << win/2 << endl;
        if (los > 1) {
            ans += (los/2);
            los -= (los/2);
        }
        if (win > 1) {
            ans += (win/2);
            los += (win/2);
            win -= (win/2);
        } 
    }
    ans++;
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