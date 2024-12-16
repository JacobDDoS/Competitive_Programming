#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int x1, x2, x3, y1, y2, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int mX, mY;
    int oX, oY;
    bool hasCorner = false;
    if (
        ((x1 == 1 && y1 ==1) || (x1 == n && y1 == 1) || (x1 == 1 && y1 == n) || (x1 == n && y1==n)) ||
        ((x2 == 1 && y2 ==1) || (x2 == n && y2 == 1) || (x2 == 1 && y2 == n) || (x2 == n && y2==n)) ||
        ((x3 == 1 && y3 ==1) || (x3 == n && y3 == 1) || (x3 == 1 && y3 == n) || (x3 == n && y3==n)) 
    ) {
        hasCorner = true;
    }

    if (x1 == x2) {
        mX = x3;
        oX = x2;
    } else if (x2 == x3) {
        mX = x1;
        oX = x2;
    } else {
        mX = x2;
        oX = x3;
    }

    if (y1 == y2) {
        mY = y3;
        oY = y2;
    } else if (y2 == y3) {
        mY = y1;
        oY = y2;
    } else {
        mY = y2;
        oY = y3;
    }

    int tX, tY; cin >> tX >> tY;

    if (hasCorner && ((mX == 2 && (mY == 2 || mY == n-1)) || (mX == n-1 && (mY == 2 || mY == n-1)))) {
        if (tX == oX || tY == oY) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    if ((tX+mX)%2 == 0 && (tY+mY)%2 == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}


int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}