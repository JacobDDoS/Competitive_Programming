// Author: JacobDDoS 
// Date: 5/27/22
// Problem: Maximum width

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> left;
    vector<int> right;

    int ptr = 0;
    int sPtr = 0;
    while (ptr != m) {
        if (s[sPtr] == t[ptr]) {
            left.push_back(sPtr+1);
            ptr++;
        }
        sPtr++;
    }

    ptr = m-1;
    sPtr = n-1;
    while (ptr >= 0) {
        if (s[sPtr] == t[ptr]) {
            right.push_back(sPtr+1);
            ptr--;
        }
        sPtr--;
    }

    reverse(right.begin(), right.end());

    int ans = 1;
    for (int i=0;i<m-1;i++) {
        ans = max(ans, right[i+1] - left[i]);
    }

    cout << ans << '\n';
    
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}