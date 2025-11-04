#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    set<int> s;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        s.insert(a);
    }

    cout << s.size()*2-1 << endl;
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