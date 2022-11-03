// Author: JacobDDoS 
// Date: 10/16/22
// Problem: B. Mystic Permutation

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

    if (n == 1) {
        cout << "-1\n";
        return;
    }

    vector<int> ans(n);
    for (int i=0;i<n;i++) {
        ans[i] = i+1;
    }

    for (int i=0;i<n;i++) {
        if (ans[i] == nums[i] && i != n-1) {
            swap(ans[i], ans[i+1]);
        } else if (ans[i] == nums[i]) {
            swap(ans[i], ans[i-1]);
        }
    }

    for (int& num : ans) {
        cout << num << " ";
    }

    cout << endl;
    
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