#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

using vi = vector<int>;
using pii = pair<int, int>;
 
#define rep(x, y, z) for (int x = (y); x <= (z); x++)
#define rep1(x, y, z, p) for (int x = (y); x <= (z); p)
#define per(x, y, z) for (int x = (y); x >= (z); x--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define endl '\n'

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n; cin >> n;
    string a, b, c; cin >> a >> b >> c;
    rep(i, 0, n-1) {
        if (a[i] != c[i] && b[i] != c[i]) {
            cout << "YES" << endl;
            return;
        }
    } 
    cout << "NO" << endl;
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