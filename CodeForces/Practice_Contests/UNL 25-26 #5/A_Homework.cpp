#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s1, s2, turn;
    cin >> s1 >> n >> s2 >> turn;

    string temp = "";
    for (int i=0;i<turn.size();i++) {
        if (turn[i] == 'D') {
            s1.push_back(s2[i]);
        } else {
            temp.push_back(s2[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    string ans = temp + s1;
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