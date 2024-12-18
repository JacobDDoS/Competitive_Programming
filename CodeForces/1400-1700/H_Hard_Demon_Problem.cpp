#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<long long>> nums;
    for (int i=0;i<n;i++) {
        vector<long long> row(n);
        for (int j=0;j<n;j++) {
            cin >> row[j];
        }
        nums.push_back(row);
    }

    for (int i=0;i<q;i++) {
        long long x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
        long long ans = 0;
        for (long long row = y1-1; row <= y2-1; row++) {
            for (long long col = x1-1; col <= x2-1; col++) {
                ans += nums[row][col] * (1 + (col - (x1-1)) + (x2-x1+1)*(row - (y1-1)));
                // cout << nums[row][col] << ": " << (1 + (col - (x1-1)) + (x2-x1+1)*(row - (y1-1))) << endl;
            }
        }

        cout << ans << " ";
    }

    cout << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}