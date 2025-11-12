#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string ans = "";
    while (n - (3-ans.size()) >= 26) {
        ans.push_back('z');
        n -= 26;
    }
    if (ans.size() == 0) {
        ans = "aa";
        ans.push_back(('a'+n-3));
    } else if (ans.size() == 1) {
        ans = "a";
        ans.push_back(('a'+n-2));
        ans.push_back('z');
    } else if (ans.size() == 2) {
        ans = "";
        ans.push_back(('a'+n-1));
        ans.push_back('z');
        ans.push_back('z');
    }
    cout << ans << endl;
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