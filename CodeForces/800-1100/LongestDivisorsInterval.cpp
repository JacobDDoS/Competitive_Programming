#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;


void solve() {
    ull n; cin >> n;
    ull cnt = 1;
    while (true) {
        if (n % cnt == 0) {
            cnt++;
            continue;
        }
        cout << cnt-1 << endl;
        break;
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