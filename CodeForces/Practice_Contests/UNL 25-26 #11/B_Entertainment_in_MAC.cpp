#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string str; cin >> str;
    string rev = str;
    reverse(rev.begin(), rev.end());
    if (rev < str) {
        cout << rev << str << endl;
    } else {
        cout << str << endl;
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