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
    int ans = 0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<n-(i-1);j++) {
            for (int k=j;k<j+i;k++) {
                ans++;
                if (nums[k]==0) ans++;
            }
        }
    } 
    cout << ans << '\n';
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