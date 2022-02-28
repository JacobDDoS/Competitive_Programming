// Author: JacobDDoS 
// Date: 2/27/22
// Problem: https://codeforces.com/problemset/problem/1537/B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    ll tl = 0, tr=0, bl=0, br=0;
    vector<tuple<ll, int, int>> pos;
    tl = x-1 + y-1;
    pos.push_back({tl, 1, 1});
    tr = n-x + y-1;
    pos.push_back({tr, n, 1});
    bl = x-1 + m-y;
    pos.push_back({bl, 1, m});
    br = n-x + m-y;
    pos.push_back({br, n, m});

    sort(pos.begin(), pos.end());

    cout << get<1>(pos[2]) << " " << get<2>(pos[2]) << " ";
    cout << get<1>(pos[1]) << " " << get<2>(pos[1]) << '\n';
    return;
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}