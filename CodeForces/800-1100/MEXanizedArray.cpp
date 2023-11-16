#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (x+1 < k  || n < k) {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    for (int i=0;i<k;i++) {
        ans += i;
    }
    if (x==k){
        x--;
    }
    ans += (n-k)*x;
    cout << ans << endl;
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