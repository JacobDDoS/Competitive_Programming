#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<string> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }
    for (int i=0;i<n-1;i++) {
        if (v[i].find("1") != string::npos) {
            if (v[i] == v[i+1]) {
                cout << "SQUARE\n";
                return;
            } else {
                cout << "TRIANGLE\n";
                return;
            }
        }
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