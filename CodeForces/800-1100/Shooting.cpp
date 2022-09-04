// Author: JacobDDoS 
// Date: 9/4/22
// Problem: B. Shooting

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> nums(n);
    for (int i=0;i<n;i++) {
        int num; cin >> num;
        nums.push_back(make_pair(num, i+1));
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(),nums.end());

    ll ans = 0;
    for (int i=0;i<n;i++) {
        ans += i*nums[i].first + 1;
    }

    cout << ans << '\n';
    for (int i=0;i<n;i++) {
        cout << nums[i].second << " ";
    }
    cout << '\n';
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