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

template <typename T>
inline T lcm(T a, T b) {return (a/gcd(a,b))*b;}

// Credit: https://cp-algorithms.com/data_structures/segment_tree.html#implementation
template <size_t N>
struct SegmentTree {
    int t[4*N];

    SegmentTree() {
        fill_n(t, 4*N, -1);
    }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            this->t[v] = a[tl];
        } else {
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return this->t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            this->t[v] = new_val;
        } else {
            int tm = (tl + tr)/2;
            if (pos <= tm) {
                update(v*2, tl, tm, pos, new_val);
            } else {
                update(v*2+1, tm+1, tr, pos, new_val);
            }
            this->t[v] = this->t[v*2] + this->t[v*2+1];
        }
    }
};


void solve() {
    int n, x, y; cin >> n >> x >> y;
    map<int, int> mp;
    int a;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a;
        ans += mp[(x-(a%x))%x][a%y];
        mp[a%x][a%y]++;
    }
    cout << ans << '\n';
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
    // solve();
}