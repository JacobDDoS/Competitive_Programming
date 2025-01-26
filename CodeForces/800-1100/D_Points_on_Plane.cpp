#include <bits/stdc++.h>

using namespace std;

unsigned long long valueAtN(unsigned long long n) {
    if (n == 1) {
        return 1;
    }
    return 1+(n-1)*(8ULL+(8ULL*(n-1)))/2ULL;
}

unsigned long long valueAtNNotZ(unsigned long long n) {
    if (n==1) {
        return 4;
    }
    return 4*n+(n-1)*(8ULL+(8ULL*(n-1)))/2ULL;
}

unsigned long long findFourN(unsigned long long n) {
    unsigned long long cur = 0;
    for (unsigned long long i=(1<<28);i>=1;(i/=2)) {
        while (valueAtNNotZ(cur+i) <= n) {
            cur += i;
        }
    }
    // cout << cur << ": " << valueAtNNotZ(cur) << endl;
    if (valueAtNNotZ(cur) < n) {
        cur++;
    }

    // cout << "final result cur: " << cur << " with: " << valueAtNNotZ(cur) << endl;
    return (cur-1)*2+1;

}


unsigned long long findEightN(unsigned long long n) {
    unsigned long long cur = 0;
    for (unsigned long long i=(1<<28);i>=1;(i/=2)) {
        while (valueAtN(cur+i) <= n) {
            cur += i;
        }
    }
    if (valueAtN(cur) < n) {
        cur++;
    }

    // cout << "final result cur: " << cur << " with: " << valueAtN(cur) << endl;
    return (cur-1)*2;

}

void solve() {
    unsigned long long n; cin >> n;
    if (n == 1) {
        cout << "0\n";
        return;
    } else if (n <= 4) {
        cout << "1\n";
        return;
    }

    cout << min(findEightN(n), findFourN(n)) << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    // cout << findEightN(5) << endl;
    // cout << findFourN(5) << endl;
}