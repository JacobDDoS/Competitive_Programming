#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int key(int k) {
    while (!(k&1)) k>>=1;
    return k;
}

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int i=0;i<n;i++) {
        mp[key(i+1)].push(v[i]);
    }

    sort(v.begin(), v.end());

    for (int i=0;i<n;i++) {
        if (v[i] != mp[key(i+1)].top()) {
            cout << "NO\n";
            return;
        }
        mp[key(i+1)].pop();
    }
    cout << "YES\n";
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