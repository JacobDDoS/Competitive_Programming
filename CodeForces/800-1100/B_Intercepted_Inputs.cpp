#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    for (int i=0;i<n;i++) {
        int currentElement = nums[i];
        int numberOfElementsInGrid = (n-2);
        if (numberOfElementsInGrid % currentElement == 0) {
            if (s.count(numberOfElementsInGrid/currentElement)) {
                cout << currentElement << " " << numberOfElementsInGrid/currentElement << '\n';
                return;
            }
        } 
        s.insert(currentElement);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}