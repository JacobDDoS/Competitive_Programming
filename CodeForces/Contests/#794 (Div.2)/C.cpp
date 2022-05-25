// Author: JacobDDoS 
// Date: 2/25/22
// Problem: C

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    if (n & 1) {
        cout << "NO\n";
        return;
    }
    sort(nums.begin(), nums.end());
    vector<int> arr;
    for (int i=0;i<n;i++) {
        if (!(i&1)) {
            arr.push_back(nums[i/2]);
        } else {
            arr.push_back(nums[n/2 + i/2]);
        }
    }

    for (int i=1;i<n-1;i++) {
        if ((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || (arr[i] < arr[i-1] && arr[i] < arr[i+1])) {
            continue;
        } else {
            cout << "NO\n";
            return;
        }
    }

    if (!((arr[0] > arr[n-1] && arr[0] > arr[1]) || (arr[0] < arr[n-1] && arr[0] < arr[1]))) {
        cout << "NO\n";
        return;
    }

    if (!((arr[n-1] > arr[0] && arr[n-1] > arr[n-2]) || (arr[n-1] < arr[0] && arr[n-1] < arr[n-2]))) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
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