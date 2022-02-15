// Author: JacobDDoS 
// Date: 2/14/22
 
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
    vector<int> ans;
    int numToLook = 1, pos=0;
    for (int i=0;i<n;i++) {
        if (nums[i]!=i+1) {
            pos = i;
            numToLook = i+1;
            break;
        }
        ans.push_back(nums[i]);
    }
    if (ans.size() != n) {
        for (int i=0;i<n;i++) {
            if (nums[i]==numToLook) {
                for (int j=i;j>=pos;j--) {
                    ans.push_back(nums[j]);
                }
                for (int j=i+1;j<n;j++) {
                    ans.push_back(nums[j]);
                }
            }
        }
    }
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
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