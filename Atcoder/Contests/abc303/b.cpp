#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m; cin >> n >> m;
    set<pair<int, int>> prs;

    for (int i=0;i<m;i++) {
        vector<int> pic(n);
        for (int i=0;i<n;i++) {
            cin >> pic[i];
        }
        for (int i=1;i<n;i++) {
            prs.insert(make_pair(pic[i-1], pic[i]));
            prs.insert(make_pair(pic[i], pic[i-1]));
        }
    }

    int totalPairs = n*(n-1)/2;
    totalPairs -= prs.size()/2;
    cout << totalPairs << endl;
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