#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n; cin >> n;
    int l, r;
    map<int, set<int>> mp;
    map<int, pair<int, int>> originalPairs;
    for (int i=0;i<n;i++) {
        cin >> l >> r;
        originalPairs[i] = make_pair(l, r);
        for (int j=l;j<=r;j++) {
            mp[i].insert(j);
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (mp[j].size() == 1) {
                int val = *mp[j].begin();
                cout << originalPairs[j].first << " " << originalPairs[j].second << " " << val << endl;
                for (int k=0;k<n;k++) {
                    if (mp[k].count(val) != 0) {
                        mp[k].erase(val);
                    }
                }
                break;
            }
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