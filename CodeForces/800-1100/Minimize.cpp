#include <bits/stdc++.h>
using namespace std;


#define ll long long


int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--)
        solve();
    return 0;
}

int solve() {
    // Break by output instead of input?
    // What are the subproblems?
    // What are the states?
    ll a, b;
    cin >> a;
    cin >> b;

    cout << (b-a) << '\n';

    return 0;
}