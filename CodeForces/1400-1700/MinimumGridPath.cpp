// Author: JacobDDoS 
// Date: 5/26/22
// Problem: Minimum Grid Path

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld; 

void solve() {
    ll n; cin >> n;
    ll minR; cin >> minR; ll minRC = minR * n;
    ll minU; cin >> minU; ll minUC = minU * n;
    ll sum = minR + minU;
    ll ans = minRC + minUC;

    ll numOfUps = 1;
    ll numOfRights = 1;
    for (ll i=2;i<n;i++) {
        ll c; cin >> c; 
        
        if (!(i&1)) {
            minR = min(minR, c);
            if (c*(n-numOfRights)+minU*(n-numOfUps)+sum < ans) {
                ans=c*(n-numOfRights)+minU*(n-numOfUps)+sum;
            }
            numOfRights++; 
        } else {
            minU = min(minU, c);
            if (c*(n-numOfUps)+minR*(n-numOfRights)+sum < ans) {
                ans=c*(n-numOfUps)+minR*(n-numOfRights)+sum;
            } 
            numOfUps++;
        }
        sum += c;
    }

    cout << ans << '\n';

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