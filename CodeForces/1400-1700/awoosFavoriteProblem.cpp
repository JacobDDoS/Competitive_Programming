// Author: JacobDDoS 
// Date: 11/27/22
// Problem: Awoo's Favorite Problem 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

int testNum = 0;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int ptr1 = 0, ptr2 = 0;
    map<char, int> haveMp;
    while (ptr2 < n) {
        if (haveMp[t[ptr2]] > 0) {
            haveMp[t[ptr2]]--;
            ptr2++;
            continue;
        }
        if ((s[ptr1] == 'c' && (haveMp['a'] != 0)) || (s[ptr1]=='a' && haveMp['b'] != 0) || haveMp['c'] != 0) {
            cout << "NO\n";
            return;
        }
        if (s[ptr1] == t[ptr2]) {
            ptr1++;
            ptr2++;
            continue;
        } 
        
        haveMp[s[ptr1]]++;
        ptr1++;
    }

    for (auto& pr : haveMp) {
        if (pr.second) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        testNum++;
        solve();
    }
    //solve();
}