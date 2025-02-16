#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> permutations;
    for (int i=0;i<n;i++) {
        vector<int> perm;
        for (int j=0;j<n-1;j++) {
            int a; cin >> a;
            perm.push_back(a);
        }
        permutations.push_back(perm);
    }

    int firstNum = 0;
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        if (++mp[permutations[i][0]] > 1) {
            firstNum = permutations[i][0];
            break;
        }
    }

    for (int i=0;i<n;i++) {
        if (permutations[i][0] != firstNum) {
            cout << firstNum << " ";
            for (int num : permutations[i]) {
                cout << num << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}