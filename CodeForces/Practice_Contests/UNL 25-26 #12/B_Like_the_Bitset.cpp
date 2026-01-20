#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;
    for (int i=0;i<n;i++) {
        if (s[i] == '1') {
            cnt++;
        }
        else {
            if (cnt >= k) {
                cout << "NO\n";
                return;
            }
            cnt = 0;
        }
    }
    if (cnt >= k) {
        cout << "NO\n";
        return;
    }

    vector<int> ans(n);
    int cur = 1;
    cout << "YES\n";
    for (int i=0;i<n;i++) {
        if (s[i] == '1') {
            ans[i] = cur++;
        }
    }
    for (int i=0;i<n;i++) {
        if (s[i] == '0') {
            ans[i] = cur++;
        }
    }
    for (int i : ans) cout << i << " ";
    cout << '\n';
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