// Author: JacobDDoS 
// Date: 11/25/22
// Problem: C

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        nums[i] = i+1;
    }

    nums[n-1] = 1;
    nums[0] = x;

    if (n-1 != x-1) {
        nums[x-1] = n;
        int pos = x-1;
        for (int i=x;i<n-1;i++) {
            if (n % (i+1) == 0 && (i+1) % (pos+1) == 0) {
                int copy = nums[i];
                nums[i] = n;
                nums[pos] = copy;
                pos = i; 
            }
        }
    }

    for (int i=0;i<n-1;i++) {
        if (nums[i] % (i+1) != 0) {
            cout << "-1\n";
            return;
        }
    }

    for (int i=0;i<n;i++) {
        cout << nums[i] << " ";
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