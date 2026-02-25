#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) cin >> nums[i];
    string s; cin >> s;
    int cur = 0;

    vector<int> prefix(n+1,0);
    for (int i=1;i<=n;i++) prefix[i] = prefix[i-1] ^ nums[i-1];
    for (int i=0;i<n;i++) {
        if (s[i] == '0') cur ^= nums[i];
    }

    int q; cin >> q;
    for (int i=0;i<q;i++) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            cur ^= (prefix[r] ^ prefix[l-1]);
        } else {
            int g; cin >> g;
            if (g == 0) {
                cout << cur << " ";
            } else {
                cout << (prefix[n] ^ cur) << " ";
            }
        }
    }
    cout << "\n";
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