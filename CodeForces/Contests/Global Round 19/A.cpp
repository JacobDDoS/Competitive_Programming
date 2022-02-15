// Author: JacobDDoS 
// Date: 2/12/22
 
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
    for (int i=0;i<n-1;i++) {
        if (nums[i+1] < nums[i]) {
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