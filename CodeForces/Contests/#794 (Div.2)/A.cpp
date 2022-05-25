// Author: JacobDDoS 
// Date: 2/25/22
// Problem: A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    double sum = 0;
    vector<int> nums;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        sum+=a;
        nums.push_back(a);
    }
    for (int i=0;i<n;i++) {
        if (nums[i] == (sum-nums[i])/(n-1)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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