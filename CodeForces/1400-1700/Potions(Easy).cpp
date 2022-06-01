// Author: JacobDDoS 
// Date: 6/1/22
// Problem: Potions (Easy Version)

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    int ans = 0;
    vector<int> nums(n);
    vector<int> neg;
    map<int, vector<int>> mp;
    map<int, bool> seen;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mp[nums[i]].push_back(i);

        if (nums[i] < 0 && !seen[nums[i]]) {
            neg.push_back(nums[i]);
            seen[nums[i]] = true;
        }
    }

    vector<ll> posi(n);
    ll counter = 0;
    for (int i=0;i<n;i++) {
        if (nums[i] >= 0) {
            counter += nums[i];
            ans++;
        }
        posi[i] = counter;
    }

    ll lowest;
    sort(neg.begin(), neg.end(), greater<int>());
    
    for (int i=0;i<neg.size();i++) {
        vector<int>& positions = mp[neg[i]];
        sort(positions.begin(), positions.end(), greater<int>());
        for (int j=0;j<positions.size();j++) {
            if (posi[positions[j]] >= abs(neg[i])) {
                lowest = 2000000001;
                for (int k=positions[j];k<n;k++) {
                    lowest = min(lowest, posi[k]);
                }
                if (lowest >= abs(neg[i])) {
                    for (int k=positions[j];k<n;k++) {
                        posi[k] += neg[i];
                    }
                    ans++;
                }
            }
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