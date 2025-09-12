#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<char> c(n);
    int hyp = 0, und = 0;
    for (int i=0;i<n;i++) {
        cin >> c[i];
        if (c[i] == '-') {
            hyp++;
        } else {
            und++;
        }
    }

    int hyp2 = hyp/2;
    hyp -= hyp2;

    cout << (long long)hyp * hyp2 * und << endl;

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