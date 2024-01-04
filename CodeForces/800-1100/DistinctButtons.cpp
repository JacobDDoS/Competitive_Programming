#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i=0;i<n;i++) {
        int f, s; cin >> f >> s;
        pair<int, int> pr;
        pr.first = f;
        pr.second = s;
        v.push_back(pr);
    }

    for (int i=0;i<n;i++) {
        if (v[i].first < 0) {
            break;
        }
        if (i==n-1) {
            cout << "YES\n";
            return;
        }
    }
    for (int i=0;i<n;i++) {
        if (v[i].first > 0) {
            break;
        }
        if (i==n-1) {
            cout << "YES\n";
            return;
        }
    }
    for (int i=0;i<n;i++) {
        if (v[i].second < 0) {
            break;
        }
        if (i==n-1) {
            cout << "YES\n";
            return;
        }
    }
    for (int i=0;i<n;i++) {
        if (v[i].second > 0) {
            break;
        }
        if (i==n-1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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