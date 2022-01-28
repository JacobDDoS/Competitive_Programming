// Author: JacobDDoS 
// Date: 1/27/22
// Problem: Convoluted Intervals

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> starts(m+1);
    vector<ll> ends(m+1);
    for (int i=0;i<n;i++) {
        ll start, end;
        cin >> start >> end;
        starts[start]++; ends[end]++;
    }

    vector<ll> wins(m*2+1);
    vector<ll> loses(m*2+1); 
    for (int i=0;i<=m;i++) {
        for (int j=0;j<=m;j++) {
            wins[i+j] += starts[i] * starts[j];
            loses[i+j] += ends[i] * ends[j];
        }
    }

    ll curWinners = 0;

    for (int i=0;i<m*2+1;i++) {
        curWinners += wins[i];
        cout << curWinners << '\n';
        curWinners -= loses[i];
    }

}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}