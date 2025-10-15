#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    v[n-1] = n-1;
    v[n-2] = n;
    for (int i=0;i<n-2;i++) {
        if (k&1) {
            v[i] = n;
        } else {
            v[i] = n-1;
        }
    }

    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
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