// Author: JacobDDoS 
// Date: 12/11/22
// Problem: Alice, Bob and Candies

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
    int aliceSize = nums[0], bobSize = 0;
    int prevA = nums[0], prevB = 0;
    int left = 1, right=n-1;
    int moves = 1;
    int bTurn = true;
    while (left <= right) {
        if (bTurn) {
            prevB = 0;
            while (prevB <= prevA && left <= right) {
                prevB += nums[right];
                bobSize += nums[right];
                right--;
            }
            moves++;
        } else {
            prevA = 0;
            while (prevA <= prevB && left <= right) {
                prevA += nums[left];
                aliceSize += nums[left];
                left++;
            }
            moves++;
        }
        bTurn = !bTurn;
    }

    cout << moves << " " << aliceSize << " " << bobSize << '\n';

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