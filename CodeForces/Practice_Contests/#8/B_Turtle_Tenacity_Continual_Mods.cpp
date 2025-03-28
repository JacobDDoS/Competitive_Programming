#include <bits/stdc++.h>
using namespace std;
                                            
// 5 3 1 -> 0
// 1 3 5 -> 1

// 2 4 4 -> 2

// 5 2 10 10 10 2 -> 1
// 2 2 5 10 10 10

// 5 2 2 10 10 10

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[0]) count++;
    }
    if (count > 1 % !(a[count]%a[0] > 0)) {
        cout << "No" << '\n';
    } else {
        cout << "yes" << '\n';
    }
    
    // for (int i = 1; i < n; i++) {
    //     if (rem % a[i] == 0) {
    //         cout << "no";
    //         return;
    //     }
    //     rem %= a[i];
    // }
    // cout << (rem == 1? "yes":"      no") << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}