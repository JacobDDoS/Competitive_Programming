// Author: JacobDDoS 
// Date: 1/1/2022
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=595

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int sum = 0;
    unordered_map<int, int> earliest;
    unordered_map<int, int> latest;
    earliest.reserve(100000);
    latest.reserve(100000);
    for (int i=1;i<=n;i++) {
        int num; cin >> num;
        sum += num;
        sum %= 7;
        if (earliest[sum] == 0) {
            earliest[sum] = i;
        }
        latest[sum] = i;
    }
    int ans = latest[0];
    for (int i=1;i<7;i++) {
        // if (latest[i] - earliest[i] + 1 > ans) {
        //     cout << "i: " << i << endl;
        // }
        ans = max(ans, latest[i] - earliest[i]);
   }
   cout << ans << '\n';
}

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}