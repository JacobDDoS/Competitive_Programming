#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    int temp; cin >> temp;
    bool flag = true;
    for (int i=0;i<m-1;i++) {
        int a; cin >> a;
        if (a != temp+1) flag = false;
        temp = a;
    }

    if (!flag) {
        cout << "1\n";
    } else {
        cout << n - temp + 1 << '\n';
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