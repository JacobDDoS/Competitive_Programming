#include <bits/stdc++.h>

using namespace std;

int numOfNumbersDivisibleByThreeOrEndInZero(int k) {
    return (k/3)+((k-3)/10)-((k-3)/30);
}

void solve() {
    int k; cin >> k;
    int ans = k + numOfNumbersDivisibleByThreeOrEndInZero(k);
    while (ans != k) {
        int temp = ans;
        ans = ans + numOfNumbersDivisibleByThreeOrEndInZero(ans) - numOfNumbersDivisibleByThreeOrEndInZero(k);
        k = temp;
    }
    
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
