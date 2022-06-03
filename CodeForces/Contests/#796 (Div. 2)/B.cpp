// Author: JacobDDoS 
// Date: 6/3/22
// Problem: B

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
    int count = 999999;
    int evenNums = 0;
    for (int i=0;i<n;i++) {
        int posi = 0;
        int copy = nums[i];
        if (!(copy & 1)) {
            evenNums++;
        }
        while (!(copy & 1)) {
            copy /= 2;
            posi++;
        }
        count = min(count, posi);
    }
    if (count) {
        evenNums--;
    }
    cout << evenNums + count << '\n';
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