#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    
    if (n & 1) {
        cout << "4\n";
        cout << "1 " << n << '\n';
        cout << "1 2" << '\n';
        cout << "2 " << n << '\n';
        cout << "2 " << n << '\n';
    } else {
        cout << "2\n";
        cout << "1 " << n << '\n';
        cout << "1 " << n << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}