// Author: JacobDDoS 
// Date: 3/10/23
// Problem: Double Sort

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<pair<int, int>> moves;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n-1;j++) {
            if ((a[j+1] < a[j]) || (a[j+1] == a[j] && b[j+1] < b[j])) {
                swap(a[j+1], a[j]);
                swap(b[j+1], b[j]);
                moves.push_back(make_pair(j+1, j+2));
            }
        }
    }

    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
        cout << moves.size() << '\n';
        for (auto& pr : moves) {
            cout << pr.first << " " << pr.second << '\n';
        }
    } else {
        cout << "-1\n";
    }

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