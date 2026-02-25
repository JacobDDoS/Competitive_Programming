#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n); 
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];

    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++) v[i] = make_pair(a[i], b[i]);

    sort(v.begin(), v.end());
    for (int i=0;i<n;i++) {
        cout << v[i].first << " ";
    }
    cout << "\n";
    for (int i=0;i<n;i++) {
        cout << v[i].second << " ";
    }
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