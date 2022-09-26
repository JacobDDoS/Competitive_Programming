// Author: JacobDDoS 
// Date: 9/26/22
// Problem: C. Digital Logarithm

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

int getNumberOfDigits(int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;

    return 10;
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    multiset<int> a;
    multiset<int> b;
    for (int i=0;i<n;i++) {
        int t; cin >> t;
        a.insert(t);
    }

    for (int i=0;i<n;i++) {
        int t; cin >> t;
        if (a.find(t) != a.end()) {
            a.erase(a.lower_bound(t));
        } else {
            b.insert(t);
        }
    }

    while (a.size()) {
        int largest;
        bool inA;
        ans++;
        if (*a.rbegin() > *b.rbegin()) {
            largest = *a.rbegin();
            a.erase(a.lower_bound(largest));
            inA = true;
        } else {
            largest = *b.rbegin();
            b.erase(b.lower_bound(largest));
            inA = false;
        }
        
        largest = getNumberOfDigits(largest);

        if (inA) {
            if (b.find(largest) != b.end()) {
                b.erase(b.lower_bound(largest));
            } else {
                a.insert(largest);
            }
        } else {
            if (a.find(largest) != a.end()) {
                a.erase(a.lower_bound(largest));
            } else {
                b.insert(largest);
            }
        }

    }

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