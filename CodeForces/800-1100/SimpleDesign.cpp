#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int x, k; cin >> x >> k;
    int sum = 0;
    for (int i=0;;i++) {
        sum = 0;
        int tmp = x + i;
        while (tmp > 0) {
            sum += (tmp%10);
            tmp /= 10;
        }
        if (sum % k == 0) {
            cout << x+i << endl;
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}