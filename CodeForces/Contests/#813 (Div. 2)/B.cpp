// Author: JacobDDoS 
// Date: 8/13/22
// Problem: B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int nums[n];
    nums[0] = 1;
    int curVal = n;
    for (int i=n-2;i>=0;i-=2) {
        if (i!=0 || !(n&1)) {
            nums[i] = curVal;
            curVal--;
            nums[i+1] = curVal;
            curVal--; 
        }  else {
            continue;
        }
    }

    for (int i=0;i<n;i++) {
        cout << nums[i] << " ";
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