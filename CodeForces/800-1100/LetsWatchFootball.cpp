#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int ans = a*c - (b*c);

    if (ans % b == 0) {
        ans /= b;
    } else {
        ans /= b;
        ans++;
    }

    cout << ans << endl;
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