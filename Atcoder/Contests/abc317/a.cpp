#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, h, x; cin >> n >> h >> x;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    for (int i=0;i<n;i++) {
        if (nums[i]+h >= x) {
            cout << i+1 << '\n';
            return;
        }
    }
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}