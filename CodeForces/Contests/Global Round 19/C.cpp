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
    ull sum = 0;
    int numOdds = 0;
    bool greaterThanOne = false;
    for (int i=1;i<n-1;i++) {
        sum += nums[i];
        if (nums[i]&1) {
            numOdds++;
        }
        if (nums[i]>=2) {
            greaterThanOne = true;
        }
    }
    ull ans = 0;
    if (!greaterThanOne || (numOdds && n==3)) {
        cout << "-1\n";
        return;
    } 
 
    ans += sum/2;
    ans += numOdds/2 + numOdds%2;
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