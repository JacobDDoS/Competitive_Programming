// Author: JacobDDoS 
// Date: 5/22/22
// Problem: C

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> a;
    set<int> f;
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        int c; cin >> c; 
        a.push_back(c);
        f.insert(c);
        mp[c]++;
    }
    
    int ans = 0;
    for (auto& pr : mp) {
        if (pr.second > 2) {
            n -= (pr.second-2);
            pr.second = 2;
        }
    }
    for (auto& pr : mp) {
        if (pr.second == 1) {
            ans = 1 + (n-1)/2;
            break;
        }
    }
    if (ans==0) {
        ans=n/2;
    }

    cout << ans << '\n';
    
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