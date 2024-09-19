#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int recursiveFunction(int root, map<int, vector<int>>& children, vector<int>& values) {
    if (children[root].size()==0) {
        // cout << "root has no children: " << root+1 << " and returns " << values[root] << endl;
        return values[root];
    }

    int smallest = 2'000'000'000;
    for (int& val : children[root]) {
        smallest = min(smallest, recursiveFunction(val, children, values));
    }

    // cout << "root: " << root+1 << " smallest: " << smallest << endl;

    if (smallest > values[root] && root != 0) {
        // cout << "root has children & does stuff: " << root+1 << " and returns " << (smallest+values[root])/2 << endl;
        return (smallest+values[root])/2;
    }

    // cout << "root has children: " << root+1 << " and returns " << smallest << endl;
    return smallest; 
}

void solve() {
    int n; cin >> n;
    vector<int> values(n);

    for (int i=0;i<n;i++) {
        cin >> values[i];
    }

    map<int, vector<int>> children;
    int x;
    for (int i=1;i<n;i++) {
        cin >> x;
        children[x-1].push_back(i);
    }

    // for (auto pr : children) {
    //     cout << pr.first << ": ";
    //     for (int x : pr.second) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    cout << values[0] + recursiveFunction(0, children, values) << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

