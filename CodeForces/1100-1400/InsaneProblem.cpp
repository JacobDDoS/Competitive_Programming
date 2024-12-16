#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    long long curK = 1;
    long long ans = 0;


    while (l1*curK <= r2) {
        int leftEndpoint = max(l1*curK, l2);
        int rightEndpoint = min(r1*curK, r2);

        if (leftEndpoint % curK != 0) {
            leftEndpoint += (curK-(leftEndpoint%curK));
        }
        

        if (rightEndpoint >= leftEndpoint) {
            ans += 1 + rightEndpoint / curK - leftEndpoint / curK;
        }
        curK *= k;
    }


    // printf("%d,%d,%d,%d,%d,%d\n", ans, k, l1, r1, l2, r2);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}