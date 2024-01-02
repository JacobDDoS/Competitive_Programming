#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int a, b; cin >> a >> b;
    int x1=a, x2=b;
    for (int i=2;i*i<=a;i++) {
        if (a % i == 0) {
            x1 = i;
            break;
        }
    }
    for (int i=2;i*i<=b;i++) {
        if (b % i == 0) {
            x2 = i;
            break;
        }
    }
    cout << b * (min(x1, x2) > 1 ? min(x1,x2) : max(x1, x2)) << endl;
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