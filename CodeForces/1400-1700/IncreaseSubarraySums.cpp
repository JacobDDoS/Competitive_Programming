// Author: JacobDDoS 
// Date: 11/28/22
// Problem: Increase Subarray Sums

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    map<int, int> bestMp;
    bestMp[0] = 0;
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    int best = 0;
    int sizeOfBest = 0;
    for (int i=1;i<=n;i++) {
        cin >> nums[i-1];
        bestMp[i] = -99999999;
    }
    for (int i=0;i<n;i++) {
        int sum = 0;
        for (int j=i;j<n;j++) {
            sum += nums[j];
            bestMp[j-i+1] = max(bestMp[j-i+1], sum);
        }
    }

    vector<int> ans(n+1);
    for (int i=0;i<=n;i++) {
        int bestSoFar = -99999999;
        for (int j=0;j<=n;j++) {
            if (bestMp[j] + x*min(i, j) > bestSoFar) {
                bestSoFar = bestMp[j] + x*min(i, j);
            }
        }
        ans[i] = bestSoFar;
    }

    for (auto& num : ans) {
        cout << num << " ";
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