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
    int oddCnt=0;
    for (int a : v) {
        if (a&1) oddCnt++;
    }

    if (oddCnt > (k + ((n-k)&1))) {
        cout << "NO\n";
        return;
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