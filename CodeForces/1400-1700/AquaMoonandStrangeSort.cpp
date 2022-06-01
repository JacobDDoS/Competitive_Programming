// Author: JacobDDoS 
// Date: 6/1/22
// Problem: AquaMoon and Strange Sort

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    map<int, int> odd;
    map<int, int> even;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (i&1) {
            odd[nums[i]]++;
        } else {
            even[nums[i]]++;
        }
    }
    sort(nums.begin(), nums.end());

    for (int i=0;i<n;i++) {
        if (i&1) {
            odd[nums[i]]--;
            if (odd[nums[i]] < 0) {
                cout << "NO\n";
                return;
            }
        } else {
            even[nums[i]]--;
            if (even[nums[i]] < 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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