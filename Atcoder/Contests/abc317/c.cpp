#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

map<int, vector<pair<ll, ll>>> mp;


set<int> visited;
ll dfs(int start) {
    visited.insert(start);

    ll best = 0;
    for (pair<ll,ll> pr : mp[start]) {
        if (visited.find(pr.first) == visited.end()) {
            best = max(best, pr.second+dfs(pr.first));
            visited.erase(pr.first);
        }
    }
    return best;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int f, t, v; cin >> f >> t >> v;
        mp[f].push_back(make_pair(t, v));
        mp[t].push_back(make_pair(f, v));
    }

    ll ans = -1;
    for (int i=1;i<=n;i++) {
        ans = max(ans, dfs(i));
        visited.erase(i);
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