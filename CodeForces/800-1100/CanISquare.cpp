#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;
 
long long int_sqrt (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}

void solve() {
    int n; cin >> n;
    ll sum = 0;
    ll num;
    for (int i=0;i<n;i++) {
        cin >> num;
        sum += num;
    }
 
    ll sqrtR = sqrt(sum);
 
    if (sqrtR * sqrtR == sum) {
        cout << "YES\n";
        return;
    }
 

    cout << "NO\n";
 
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}