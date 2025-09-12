#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> days(n);
    for (int i=0;i<n;i++) {
        cin >> days[i];
    }
    for (int i=0;i<n;i++) {
        if (days[i] == 0 && k+i-1 < n) {
            bool good = true;
            int start = i;
            for (;i<n && i<start+k;i++) {
                if (days[i] == 1) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans++;
            }
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