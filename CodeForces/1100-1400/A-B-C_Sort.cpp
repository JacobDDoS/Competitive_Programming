// Author: JacobDDoS 
// Date: 11/2/22
// Problem: D. A-B-C Sort
 
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
 
    reverse(a.begin(),a.end());
    
    vector<int> b(n);
    int leftPtr = 0;
    int rightPtr = n-1;
    for (int i=0;i<n;i+=2) {
        if (leftPtr == rightPtr) {
            if (leftPtr != 0 & b[leftPtr-1] < a[i]) {
                cout << "NO\n";
                return;
            } else if (rightPtr != n-1 && b[rightPtr+1] < a[i]) {
                cout << "NO\n";
                return;
            }
        } else {
            if (leftPtr == 0) {
                b[leftPtr] = a[i];
                b[rightPtr] = a[i+1];
            } else {
                if (a[i] <= b[leftPtr-1] && a[i+1] <= b[rightPtr+1] && a[i] <= b[rightPtr+1] && a[i+1] <= b[leftPtr-1]) {
                    b[leftPtr] = a[i];
                    b[rightPtr] = a[i+1];
                } else {
                    cout << "NO\n";
                    return;
                }
            }
            leftPtr++;
            rightPtr--;
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
        solve();
    }
    //solve();
}