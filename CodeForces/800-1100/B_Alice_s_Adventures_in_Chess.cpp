#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int curX = 0, curY = 0;
    do {
        for (int i=0;i<n;i++) {
            if (s[i] == 'N') {
                curY++;
            } else if (s[i] == 'E') {
                curX++;
            } else if (s[i] == 'W') {
                curX--;
            } else {
                curY--;
            }

            if (curX == a && curY == b) {
                cout << "YES\n";
                return;
            }
        }
        if (curX == 0 && curY == 0) {
            cout << "NO\n";
            return;
        }
    } while (curX <= 20 && curY <= 20 && curX >= -10 && curY >= -10);

    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}