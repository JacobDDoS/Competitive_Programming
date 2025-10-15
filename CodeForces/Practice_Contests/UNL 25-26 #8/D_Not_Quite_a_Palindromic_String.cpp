#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> v(2, 0);
    for (int i=0;i<n;i++) {
        v[s[i]-'0']++;
    }

    k = n/2 - k;

    v[0] -= k;
    v[1] -= k;
    if (!(v[0]&1) && !(v[1]&1) && v[0] >= 0 && v[1] >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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