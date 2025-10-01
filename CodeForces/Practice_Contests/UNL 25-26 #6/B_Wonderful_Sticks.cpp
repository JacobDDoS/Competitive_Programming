#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s; cin >> s;
    vector<int> ans(n);
    int cur = 1;
    for (int i=n-1;i>=0;i--) {
        if (s[i] == '<') {
            ans[i+1] = cur;
            cur++;
        }
    }
    ans[0] = cur;
    cur++;
    for (int i=0;i<n;i++) {
        if (s[i] == '>') {
            ans[i+1] = cur;
            cur++;
        }
    }
    for (int i : ans) {
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