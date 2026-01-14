#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> cnt(n+1, 0);
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int c = 0, ans = 0;
    for (int i=0;i<k;i++) {
        if (!cnt[i]) c++;
    }
    cnt[k] -= c;
    ans = c + max(0, cnt[k]);
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