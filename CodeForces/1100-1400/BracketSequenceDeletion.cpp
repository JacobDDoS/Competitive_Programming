// Author: JacobDDoS 
// Date: 5/6/22
// Problem: Bracket Sequence Deletion

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int totalOperations = 0;
    int l=0, r=0;
    while (r<s.size() && l < s.size()-1 ) {
        if (s[l] == '(') {
            l += 2;
            r += 2;
            totalOperations++;
        } else if (s[l] == ')') {
            r = l+1;
            while (s[r] != ')' && r < s.size()) {
                r++;
            }
            if (r == s.size()) {
                break;
            } else {
                l = r+1;
                r = l;
                totalOperations++;
            }
        }
    }
    cout << totalOperations << " " << s.size() - l << '\n';
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