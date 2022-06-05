// Author: JacobDDoS 
// Date: 6/4/22
// Problem: Three Indices

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int l, r;
    for (int i=1;i<n;i++) {
        l = n+1;
        r = n+1;
        for (int j=i-1;j>=0;j--) {
            if (nums[j] < nums[i]) {
                l = j+1;
                break;
            }
        }

        for (int j=i+1;j<n;j++) {
            if (nums[j] < nums[i]) {
                r = j+1;
                break;
            }
        }
        if (l < n+1 && r < n+1) {
            cout << "YES\n";
            cout << l << " " << i+1 << " " << r << '\n';
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