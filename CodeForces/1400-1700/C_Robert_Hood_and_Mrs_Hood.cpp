#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, d, k; cin >> n >> d >> k;
    vector<pair<int, int>> v(k), vb(k);
    for (int i=0;i<k;i++) {
        int a, b; cin >> a >> b;
        v[i] = make_pair(a, b);
        vb[i] = make_pair(b, a);
    }
    sort(v.begin(), v.end());
    sort(vb.begin(), vb.end());

    multiset<pair<int, int>> q;
    int vPtr = 0, vbPtr = 0;
    int maxPtr = 1, minPtr = 1;
    int maxBest = -1, minBest = 999999999;
    for (int i=1;i<=n-(d-1);i++) {
        while (vPtr < k && v[vPtr].first >= i && v[vPtr].first <= (i+d-1)) {
            q.insert(v[vPtr]);
            vPtr++;
        }

        // cout << "q.front(): " << q.front().first << ", " << q.front().second << endl;
        while (vbPtr < k && vb[vbPtr].first <= i-1) {
            q.erase(make_pair(vb[vbPtr].second, vb[vbPtr].first));
            vbPtr++;
        }
        

        if ((int)q.size() > maxBest) {
            maxBest = q.size();
            maxPtr = i;
        }

        // cout << "q.size(): " << q.size() << endl;
        if ((int)q.size() < minBest) {
            minBest = q.size();
            minPtr = i;
        }
        
    }

    cout << maxPtr << " " << minPtr << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}