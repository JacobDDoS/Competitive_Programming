#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

void solve() {
    int n, glGCD; cin >> n;
    vector<int> nums(n);
    cin >> nums[0];
    glGCD = nums[0];
    for (int i=1;i<n;i++) {
        cin >> nums[i];
        glGCD = gcd(glGCD, nums[i]);
    }

    if (glGCD == 1) {
        cout << "0\n";
        return;
    }

    for (int i=0;i<=(1<<(n-1));i++) {
        // cout << "i: " << i << endl;
        int curGCD = glGCD, cost = 0;
        for (int j=1;j<=i;j<<=1) {
            // cout << "j: " << j << endl;
            // cout << "before gcd: " << curGCD << endl;
            if (i&j) {
                curGCD = gcd(curGCD, n-(j-1));
                cost += j;
            }
            // cout << "After gcd: " << curGCD << " done by " << n-(j-1) << endl;
        }
        if (curGCD == 1) {
            cout << cost << endl;
            return;
        }
    }
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