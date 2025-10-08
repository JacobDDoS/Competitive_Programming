#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int sum(int n) {
    return (n*(n-1))/2;
}

int maxN(int n) {
    int cur = 0;
    for (int i=256;i>=1;i/=2) {
        while (sum(cur+i) <= n) {
            cur += i;
        }
    }
    return cur;
}

void solve()
{
    int n; cin >> n;
    int ans = 0;
    int curX = 0, curY = 0;
    vector<pair<int, int>> v;
    while (n) {
        int staffs = maxN(n);
        ans += staffs;
        n -= sum(staffs);
        for (int i=0;i<staffs;i++) {
            v.push_back(make_pair(curX++, curY));
        }
        curY++;
    }
    cout << ans << endl;
    for (auto& pr : v) {
        cout << pr.first << " " << pr.second << "\n";
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