// Author: JacobDDoS 
// Date: 5/7/22
// Problem: Lord of the Values

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    ll nums[n];
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    cout << 3*n << '\n';
    for (int i=0;i<n;i+=2) {
        cout << "1 " << i+1 << " " << i+2 << "\n";
        cout << "2 " << i+1 << " " << i+2 << "\n";
        cout << "2 " << i+1 << " " << i+2 << "\n";
        cout << "1 " << i+1 << " " << i+2 << "\n";
        cout << "2 " << i+1 << " " << i+2 << "\n";
        cout << "2 " << i+1 << " " << i+2 << "\n";
    }
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