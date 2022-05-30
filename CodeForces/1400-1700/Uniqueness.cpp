// Author: JacobDDoS 
// Date: 5/30/22
// Problem: Uniqueness

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int ans = n-1;
    map<int, int> mp;
    vector<int> nums;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        nums.push_back(a);
    }
    
    for (int i=0;i<n;i++) {
        mp.clear();
        bool isValid = true;
        int goodEndIndex = n;
        for (int j=0;j<i;j++) {
            mp[nums[j]]++;
            if (mp[nums[j]] >= 2) {
                isValid = false;
                break;
            }
        }
        for (int j=n-1;j>=i;j--) {
            mp[nums[j]]++;
            if (mp[nums[j]]==1) {
                goodEndIndex = j;
            } else {
                break;
            }
        }

        if (isValid) {
            ans = min(ans, goodEndIndex-i);
        }
    }

    cout << ans << '\n';

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