// Author: JacobDDoS 
// Date: 1/27/22
// Problem: Phoenix and Socks

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    int cp = l;
    int ans = n/2;
    map<int, int> lmp;
    map<int, int> rmp;
    for (int i=0;i<n;i++) {
        int num; cin >> num;
        if (cp) {
            lmp[num]++;
            cp--;
        } else {
            rmp[num]++;
        }
    }
    if (l > r) {
        auto temp = lmp;
        lmp = rmp;
        rmp = temp;
        int t = l;
        l = r;
        r = t;
    }
    if (l != r) {
        int dif = (r-l)/2;
        set<pair<int, int>> rmptoset;
        for (auto& pr : rmp) {
            rmptoset.insert(make_pair(pr.second, pr.first));
        }
        for (auto& m : rmptoset) {
            int nog = 0;
            if (lmp[m.second] < m.first) {
                nog = min((m.first - lmp[m.second])/2, dif);
            }
            rmp[m.second] -= nog;
            lmp[m.second] += nog;
            r -= nog;
            l += nog;
            dif-=nog;
            ans+=nog;
            if (r==l) break;
        }
        while (l != r) {
            rmptoset.clear();
            for (auto& pr : rmp) {
                rmptoset.insert(make_pair(pr.second, pr.first));
            }
                for (auto& m : rmptoset) {
                    int nog = 0;
                    if (lmp[m.second] < m.first) {
                        nog = min((m.first - lmp[m.second]), dif);
                    }
                    rmp[m.second] -= nog;
                    lmp[m.second] += nog;
                    r -= nog;
                    l += nog;
                    dif-=nog;
                    ans+=nog;
                    if (r==l) break;
            }
        }
    }
    
    for (auto& m : lmp) {
        ans -= min(m.second, rmp[m.first]);
    }
    cout << ans << '\n';
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