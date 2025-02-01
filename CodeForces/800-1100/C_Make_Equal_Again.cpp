#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    int leftPtr = 0, rightPtr = n-1;
    int ans = 999999999;

    // Assume left side works
    while (leftPtr != n-1 && nums[leftPtr+1] == nums[leftPtr]) {
        leftPtr++;
    }
    while (rightPtr != 0 && nums[rightPtr] == nums[leftPtr] && leftPtr!=rightPtr) {
        rightPtr--;
    }

    ans = rightPtr-leftPtr;

    // Assume right side works
    leftPtr = 0, rightPtr = n-1;
    while (rightPtr != 0 && nums[rightPtr-1] == nums[rightPtr]) {
        rightPtr--;
    }
    while (leftPtr != n-1 && nums[leftPtr] == nums[rightPtr] && rightPtr != leftPtr) {
        leftPtr++;
    }

    ans = min(ans, rightPtr-leftPtr);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}