// Author: JacobDDoS 
// Date: 8/16/23    
// Problem: A. Dalton The Teacher

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> students(n);
    for (int i=0;i<n;i++) {
        cin >> students[i];
    }
    int sum = 0;
    for (int i=0;i<n;i++) {
        if (students[i]==i+1) {
            sum++;
        }
    }
    int ans = sum/2 + (sum&1?1:0);
    cout << ans << endl;
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