#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

map<int, pair<int, int>> mp;

void solve()
{
    string s; cin >> s;
    int n = stoi(s);
    double sq = sqrt((double)n);
    if (abs(sq - round(sq)) < 1e-5) {
        cout << (int)sq << " " << "0" << endl;
    } else {
        cout << "-1" << endl;
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