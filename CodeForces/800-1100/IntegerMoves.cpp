// Author: JacobDDoS 
// Date: 5/6/22
// Problem: Integer Moves

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    double x, y, whole, fraction; cin >> x >> y;
    if (x==0 && y==0) {
        cout << "0\n";
        return;
    }
    fraction = modf(sqrt((x*x + y*y)), &fraction);
    if (fraction == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
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