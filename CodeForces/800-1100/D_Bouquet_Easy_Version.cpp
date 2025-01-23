#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
void solve() {
    long long n; cin >> n;
    long long m; cin >> m;
    vector<long long> flowers(n);
    for (int i=0;i<n;i++) {
        cin >> flowers[i];
    }
 
    sort(flowers.begin(), flowers.end());
 
    long long leftPtr = 0, rightPtr = 0;
    long long curCost = flowers[0];
    long long ans = 0;
    if (curCost <= m) {
        ans = curCost;
    }
    while (leftPtr != n-1) {
        while (curCost > m || (flowers[rightPtr] - flowers[leftPtr]) > 1) {
            curCost -= flowers[leftPtr];
            leftPtr++;
        }
 
        ans = max(ans, curCost);
 
        if (rightPtr != n-1) {
            rightPtr++;
            curCost += flowers[rightPtr];
        } else {
            break;
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