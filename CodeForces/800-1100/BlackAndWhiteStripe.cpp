// Author: JacobDDoS 
// Date: 8/23/23
// Problem: D. Black and White Stripe

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int best = 999999;
    int left=0, right=0;
    int numOfWhite = 0;
    for (int i=0;i<k;i++) {
        if (s[right]=='W') {
            numOfWhite++;
        }
        right++;
    }
    while (right <= n) {
        best = min(best, numOfWhite);


        right++;
        if (s[left]=='W') {
            numOfWhite--;
        }
        left++;
        if (right <=n && s[right-1]=='W') {
            numOfWhite++;
        }
    }

    cout << best << endl;
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