#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n";
        cout << n << '\n';
        for (int i=0;i<n;i++) {
            cout << "1 ";
        }
        cout << endl;
        return;
    } else if (k>=2&&!(n&1)) {
        cout << "YES\n";
        cout << n/2 << '\n';
        for (int i=0;i<n/2;i++) {
            cout << "2 ";
        }
        cout << endl;
        return;
    } else if (k > 2 && n > 2) {
        cout << "YES\n";
        cout << n/2 << '\n';
        for (int i=0;i<n/2-1;i++) {
            cout << "2 ";
        }
        cout << "3" << endl;
        return;
    } else {
        cout << "NO\n";
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