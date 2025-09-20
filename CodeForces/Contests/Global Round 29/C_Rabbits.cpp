#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<bool> safe(n, false);
    if (s[0] == '0' && n > 1) {
        safe[1] = true;
    }
    if (s[n-1] == '0' && n > 1) {
        safe[n-2] = true;
    }
    
    int cnt = 0, init = 0;
    for (int i=0;i<n;i++) {
        cnt = 0;
        init = i;
        while (s[i] == '0') {
            cnt++;
            i++;
        }
        if (cnt > 1) {
            if (i < n) {
                safe[i] = true;
            }
            if (init-1 >= 0) {
                safe[init-1] = true;
            }
        }
    }

    int islandCnt = 0;
    bool isSafe = false;
    for (int i=1;i<n-1;i++) {
        isSafe = false;
        while (i<n-1 && s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
            if (safe[i-1] || safe[i+1]) isSafe = true;
            islandCnt++;
            i+=2;
        }
        if ((islandCnt & 1) == 0 || isSafe) {
            ;
        } else {
            cout << "NO\n";
            return;
        }
        islandCnt = 0;
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