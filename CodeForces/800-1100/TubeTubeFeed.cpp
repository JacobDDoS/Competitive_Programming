// Author: JacobDDoS 
// Date: 6/16/23
// Problem: TubeTube Feed

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> dur(n);
    vector<int> ent(n);
    for (int i=0;i<n;i++) {
        cin >> dur[i];
    }
    for (int i=0;i<n;i++) {
        cin >> ent[i];
    }
    int idx=-1;
    int val=-1;
    for (int i=0;i<n;i++) {
        if (i+dur[i] <= t && ent[i] > val) {
            idx = i+1;
            val = ent[i];
        }
    }

    cout << idx << '\n';
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