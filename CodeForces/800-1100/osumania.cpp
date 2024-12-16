#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> notes(n);
    for (int i=0;i<n;i++) {
        cin >> notes[i];
    }

    for (int i=n-1;i>=0;i--) {
        cout << notes[i].find('#')+1 << ' ';
    }
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}