#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    vector<int> perm(n);
    for (int i=n-1;i>=0;i--) {
        int end = i;
        for (int j=i-1;j>=0;j--) {
            if (nums[j] == nums[i]) {
                end--;
            } else {
                break;
            }
        }
        if (end == i) {
            cout << "-1\n";
            return;
        }

        perm[end] = i+1;
        for (int j=end+1;j<=i;j++) {
            perm[j] = j;
        }

        i = end;
    }

    for (auto& num : perm) {
        cout << num << " ";
    }
    cout << endl;
    
    

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}