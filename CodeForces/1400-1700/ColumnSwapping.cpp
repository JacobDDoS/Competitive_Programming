// Author: JacobDDoS 
// Date: 5/21/22
// Problem: Column Swapping

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> nums;
    for (int i=0;i<n;i++) {
        vector<int> row;
        for (int j=0;j<m;j++) {
            int a; cin >> a;
            row.push_back(a);
        }
        nums.push_back(row);
    }
    
    set<int> toSwitch;

    for (int i=0;i<nums.size();i++) {
        vector<int> cRow = nums[i];
        sort(cRow.begin(), cRow.end());
        for (int j=0;j<nums[i].size();j++) {
            if (nums[i][j] != cRow[j] && toSwitch.size() <= 2) {
                toSwitch.insert(j);
            }
        }
        if (toSwitch.size() > 2) break;
    }

    if (toSwitch.size() > 2) {
        cout << "-1\n";
        return;
    } else if (toSwitch.size() == 0) {
        cout << "1 1\n";
        return;
    } else {
        int a = *toSwitch.begin();
        int b = *(--toSwitch.end());
        // cout << "a: " << a << " b: " << b << endl;
        for (int i=0;i<nums.size();i++) {
            int copy = nums[i][a];
            nums[i][a] = nums[i][b];
            nums[i][b] = copy;
        }
        for (int i=0;i<nums.size();i++) {
            for (int j=1;j<nums[i].size();j++) {
                if (nums[i][j]<nums[i][j-1]) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        cout << a+1 << " " << b+1 << '\n';
    }


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