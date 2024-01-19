#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    ull n; cin >> n;
    ull x = 0;
    for (ull i=(1LL<<63);i>0;i>>=1) {
        // cout << "value: " << ((x+i)*((x+i)-1))/2 << endl;
        // cout << "x: " << x << " i:" << i << endl;
        while (((x+i)*((x+i)-1))/2 <= n) {
            x += i;
        }
    }

    cout << x + (n-((x*(x-1))/2)) << endl;
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