// Author: JacobDDoS 
// Date: 8/19/23
// Problem: D. Gold Rush

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m; cin >> n >> m;
    queue<int> nums;
    nums.push(n);
    while (!nums.empty()) {
        int c = nums.front();
        nums.pop();
        if (c==m) {
            cout << "YES\n";
            return;
        }
        if (c < m || c % 3 != 0) {
            continue;
        }

        nums.push(c/3); 
        nums.push(c/3*2);
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