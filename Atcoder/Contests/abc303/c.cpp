#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m, h, k; cin >> n >> m >> h >> k;
    string s; cin >> s;
    map<pair<int, int>, bool> seenPr;
    set<pair<int, int>> items;
    for (int i=0;i<m;i++) {
        int x, y; cin >> x >> y;
        items.insert(make_pair(x, y));
    }

    int x = 0, y = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == 'R') x++;
        else if (s[i] == 'L') x--;
        else if (s[i] == 'U') y++;
        else if (s[i] == 'D') y--;

        h--;
        if (h < 0) {
            cout << "No\n";
            return;
        }

        if (items.find(make_pair(x, y))!= items.end() && seenPr[make_pair(x, y)]==false && h < k) {
            seenPr[make_pair(x, y)]=true;
            h = k;
        }
    }

    cout << "Yes\n";
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}