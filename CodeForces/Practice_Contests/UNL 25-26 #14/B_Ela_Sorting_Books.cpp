#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> v(26, 0);
    for (char c : s) {
        v[c-'a']++;
    }
    string ans = "";
    for (int i=0;i<k;i++) {
        int ptr = 0, m = n/k;
        while (v[ptr] && m) {
            v[ptr]--;
            ptr++;
            m--;
        }
        ans.push_back('a'+ptr);
    }
    cout << ans << '\n';
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