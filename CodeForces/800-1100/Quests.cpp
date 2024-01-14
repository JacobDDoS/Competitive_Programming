#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }

    ll total = 0;
    ll ans = 0; 
    ll best = 0;

    for (int i=1;i<=min(n, k);i++) {
        total += a[i-1];
        best = max(best, b[i-1]);

        ans = max(ans, total + best*(k-i));
    }

    cout << ans << endl;
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