#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'T')
        {
            ans.push_back('T');
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'T')
        {
            ans.push_back(s[i]);
        }
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