// Author: JacobDDoS 
// Date: 7/20/23
// Problem: A. One and Two

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, c=0, a=0; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (nums[i]==2) {
            c++;
        }
    }

    for (int i=0;i<n;i++) {
        if (nums[i]==2) {
            c--;
            a++;
        }

        if (a==c) {
            cout << i+1 << '\n';
            return;
        }

    }

    cout << "-1\n";

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