// Author: JacobDDoS 
// Date: 7/16/22
// Problem: B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> nums;
    for (int i=1;i<=n;i++) {
        if (l % i == 0) {
            nums.push_back(l);
        } else {
            if (l+i-(l%i) > r) {
                cout << "NO\n";
                return;
            }
            nums.push_back(l+i-(l%i));
        }
    }

    cout << "YES\n";
    for (int i=0;i<n;i++) {
        cout << nums[i] << " ";
    }
    cout << '\n';

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