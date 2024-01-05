#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    ll mul = 1;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mul *= nums[i];
    }

    if (2023 % mul == 0) {
        cout << "YES\n";
        cout << 2023/mul << " ";
        for (int i=1;i<k;i++) {
            cout << "1 ";
        }
        cout << endl;
        return;
    }
    cout << "NO\n";
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