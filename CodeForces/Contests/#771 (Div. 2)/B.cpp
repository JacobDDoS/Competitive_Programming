// Author: JacobDDoS 
// Date: 2/14/22
 
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;
 
void solve() {
    int n; cin >> n;
    int bOdd=-1, bEven=-1;
    int num=0;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    for (int i=0;i<n;i++) {
        if (nums[i] % 2 == 0) {
            if (nums[i] > bEven) {
                bEven = nums[i];
            }
            if (nums[i] < bEven) {
                cout << "No\n";
                return;
            }
        } else {
            if (nums[i] > bOdd) {
                bOdd = nums[i];
            }
            if (nums[i] < bOdd) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "YES" << endl;
}
 
int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    //solve();
}