#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    vector<int> nums(4);
    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 0;
    nums[3] = 0;
    for (int i=0;i<4;i++) {
        cin >> nums[i];
    }
    int ans = 0;
    int score = 0;
    for (int i=0;i<2;i++) {
        for (int j=2;j<4;j++) {
            score = 0;
            if (nums[i] > nums[j]) {
                score++;
            }
            if (nums[i] < nums[j]) {
                score--;
            }
 
            int otherI;
            int otherJ;
            if (i == 0) {
                otherI = 1;
            } else {
                otherI = 0;
            }

            if (j == 2) {
                otherJ = 3;
            } else {
                otherJ = 2;
            }
            if (nums[otherI] > nums[otherJ]) {
                score++;
            }
            if (nums[otherI] < nums[otherJ]) {
                score--;
            }
 
            if (static_cast<int>(score) > 0) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}