#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    vector<int> ans(n);
    for (int i=1;i<=n;i++) {
        ans[i-1] = i;
    }

    int add = 0;
    for (int i=0;i<n;i++) {
        if (ans[i]+add == nums[i]) {
            add++;
        }
        ans[i] += add;
    }

    cout << ans[n-1] << endl;
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