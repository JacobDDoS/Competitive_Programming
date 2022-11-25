// Author: JacobDDoS 
// Date: 11/25/22
// Problem: A

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++) {
        cout << s[i];
    }

    for (int i=s.size()-1;i>=0;i--) {
        cout << s[i];
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