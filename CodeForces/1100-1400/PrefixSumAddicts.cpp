#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> s(k);
    for (int i=0;i<k;i++) {
        cin >> s[i];
    }
    vector<ll> dif;
    for (int i=k-1;i>0;i--) {
        dif.push_back(s[i]-s[i-1]);
    }

    for (int i=1;i<dif.size();i++) {
        if (dif[i]>dif[i-1]) {
            cout << "NO\n";
            return;
        }
    }

    if (k==1) {
        cout << "YES\n";
        return;
    }

    if (n==k && s[0] <= dif[dif.size()-1]) {
        cout << "YES\n";
        return;
    }


    if (s[0] - dif[dif.size()-1]*(n-k) <= dif[dif.size()-1]) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";

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