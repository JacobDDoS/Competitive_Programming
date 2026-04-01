#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, x; cin >> n >> x;
    vector<int> v(n);
    int cur = 0;
    for (int i=0;i<n;i++) {
        if ((x&i) == i) {
            v[i] = i;
            cur |= i;
        } else {
            v[i] = x;
            cur |= x;
        }
    }
    if (cur != x) {
        v[n-1] = x;
    }
    for (auto num : v) cout << num << " ";
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