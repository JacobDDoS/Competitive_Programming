#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    int nO = 0;
    bool hasZ = false;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (nums[i] < 0) {
            nO++;
        }
        if (nums[i] == 0) {
            hasZ = true;
        }
    }

    if (hasZ || nO % 2 == 1) {
        cout << "0\n";
        return;
    }

    cout << "1\n1 0\n";



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