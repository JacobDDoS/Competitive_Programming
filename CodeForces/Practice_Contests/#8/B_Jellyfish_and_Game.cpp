#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a1(n);
    for (int i=0;i<n;i++) {
        cin >> a1[i];
    }
    vector<ll> a2(m);
    for (int i=0;i<m;i++) {
        cin >> a2[i];
    }

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    if (a1[0] < a2[a2.size()-1]) {
        swap(a1[0], a2[a2.size()-1]);
    }
    k--;
    if (k>0) {
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        if (a2[0] < a1[a1.size()-1]) {
            swap(a2[0], a1[a1.size()-1]);
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        k--;
    }

    if (k>0 && k&1) {
        if (a1[0] < a2[a2.size()-1]) {
            swap(a1[0], a2[a2.size()-1]);
        }
    }

    ll sum = 0;
    for (int i=0;i<n;i++) {
        sum += a1[i];
    }
    cout << sum << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}