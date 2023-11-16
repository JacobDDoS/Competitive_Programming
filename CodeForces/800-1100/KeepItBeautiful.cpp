#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int q; cin >> q;
    string ans = "";
    vector<int> nums;
    bool isSwitched = false;
    for (int i=0;i<q;i++) {
        int n; cin >> n;
        if (nums.size()==0 || (isSwitched && n >= nums[nums.size()-1] && n <= nums[0]) || (!isSwitched && n >= nums[nums.size()-1]) || (!isSwitched && n <= nums[0])) {
            if (nums.size()>0 && !isSwitched && n <= nums[0] && n < nums[nums.size()-1]) {
                isSwitched = true;
            }
            ans.push_back('1');
            nums.push_back(n);
        } else {
            ans.push_back('0');
        }
    }
    cout << ans << endl;
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