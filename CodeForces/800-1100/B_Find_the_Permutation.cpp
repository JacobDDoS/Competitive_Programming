#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<string> strs(n);
    vector<int> ans;
    for (int i=0;i<n;i++) {
        cin >> strs[i];
    }
    
    for (int i=0;i<n;i++) {
        int cnt = 0;
        for (int j=0;j<i;j++) {
            if (strs[i][j] == '1') {
                cnt++;
            }
        }
        ans.insert(ans.begin() + cnt, i+1);
    }

    for (int v : ans) {
        cout << v << " ";
    }
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}