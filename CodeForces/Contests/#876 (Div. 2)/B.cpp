// Author: JacobDDoS 
// Date: 
// Problem: 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> l(n);
    for (int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        l[i] = make_pair(a, b);
    }

    sort(l.begin(), l.end(), [](auto& left, auto& right) {
        if (left.first != right.first) {
            return left.first < right.first;
        } else {
            return left.second > right.second;
        }
    });

    ll ans = 0;
    int turnedOn = 0;
    int curNum = 1;
    for (auto& pr : l) {
        if (pr.first < curNum) {
            continue;
        } else if (pr.first > curNum) {
            curNum = pr.first;
            turnedOn = 0;
        }
        ans += pr.second;
        turnedOn++;
        if (turnedOn == curNum) {
            curNum++;
            turnedOn = 0;
        }
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