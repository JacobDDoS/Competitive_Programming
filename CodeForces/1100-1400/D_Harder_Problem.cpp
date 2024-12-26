#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    set<int> posN;
    for (int i=1;i<=n;i++) {
        posN.insert(i);
    }

    for (int i=0;i<n;i++) {
        if (posN.count(nums[i])) {
            cout << nums[i] << " ";
            posN.erase(nums[i]);
        } else {
            int head = *posN.begin();
            cout << head << " ";
            posN.erase(head);
        }
    }
    cout << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}