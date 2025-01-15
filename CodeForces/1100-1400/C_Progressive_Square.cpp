#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, c, d; cin >> n >> c >> d;
    map<int, int> mp;
    int minNum = INT32_MAX;
    for (int i=0;i<n*n;i++) {
        int num; cin >> num;
        minNum = min(minNum, num);
        mp[num]++;
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int num = minNum+d*i+c*j;
            if (mp[num] <= 0) {
                cout << "NO\n";
                return;
            } else {
                mp[num]--;
            }
        }
    }

    cout << "YES\n";

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}