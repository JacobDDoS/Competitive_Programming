#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    vector<string> grid(8);
    for (int i=0;i<8;i++) {
        cin >> grid[i];
    }
    for (int i=0;i<8;i++) {
        bool good = true;
        for (int j=1;j<8;j++) {
            if (grid[i][j] != grid[i][0] || grid[i][j] != 'R' || grid[i][0] != 'R') good = false;
        }
        if (good) {
            cout << grid[i][0] << '\n';
            return;
        }
    }

    for (int i=0;i<8;i++) {
        bool good = true;
        for (int j=1;j<8;j++) {
            if (grid[j][i] != grid[0][i] || grid[j][i] != 'B' || grid[0][i] != 'B') good = false;
        }
        if (good) {
            cout << grid[0][i] << '\n';
            return;
        }
    }

    cout << "ERROR\n";
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