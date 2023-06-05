// Author: JacobDDoS 
// Date: 6/3/23
// Problem: C

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    if (a[n-1] == 1) {
        cout << "NO\n";
        return;
    }
    vector<int> s;

    for (int i=n-1;i>=0;i--) {
        if (i!=0 && a[i-1] != 1) {
            s.push_back(0);
        } else if (i!=0&&a[i-1]==1) {
            int cnt = 0;
            while (a[i-1] == 1) {
                s.push_back(0);
                i--;
                cnt++;
            }
            s.push_back(cnt);
        } else {
            s.push_back(0);
        }
    }

    cout << "YES\n";
    for (int i=0;i<s.size();i++) {
        cout << s[i] << " ";
    }
    cout << '\n';
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