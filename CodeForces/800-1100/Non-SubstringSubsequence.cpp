// Author: JacobDDoS 
// Date: 1/8/2022
// Problem: https://codeforces.com/problemset/problem/1451/B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    for (int i=0;i<q;i++) {
        int lo, hi; cin >> lo >> hi;
        int ptr = 0; int ptr2 = lo-1;
        for (int i=0;i<hi-lo;i++) {
            ptr = 0; ptr2 = lo-1;
            while (ptr2 != hi && ptr < s.length()) {
                if (s[ptr] == s[ptr2]) {
                    if (ptr2-(lo-1) == i) {
                        ptr++;
                    } 
                    ptr2++;
                }
                ptr++;
            }
            if (ptr2 == hi) {
                break;
            }
        }
        
        if (ptr2 == hi) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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