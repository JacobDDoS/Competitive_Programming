// Author: JacobDDoS 
// Date: 7/21/23
// Problem: A. The Man who became a God

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    vector<int> c;
    for (int i=0;i<n-1;i++) {
        c.push_back(abs(nums[i]-nums[i+1]));
    }

    sort(c.begin(), c.end());
    for (int i=0;i<k-1;i++) {
        c.pop_back();
    }

    int sum=0;
    for (int i=0;i<c.size();i++) {
        sum+=c[i];
    }
    cout << sum << '\n';
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