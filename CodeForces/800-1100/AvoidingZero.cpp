//This is a 900 rated problem 
//Here is the question: https://codeforces.com/problemset/problem/1427/A


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, [](int x, int y){return x>y;});
    int sum = 0;
    bool first = true;
    bool second = true;
    for (auto& i : arr) {
        sum+=i;
        if (sum == 0) {
            first = false;
            break;
        }
    }
    sum = 0;
    reverse(arr, arr+n);
    for (auto& i : arr) {
        sum+=i;
        if (sum == 0) {
            second = false;
            break;
        }
    }
    if (first || second) {
        cout << "YES\n";
        if (second) {
            for (auto& i : arr) {
                cout << i << " ";
            }
        } else {
            reverse(arr, arr+n);
            for (auto& i : arr) {
                cout << i << " ";
            }
        }
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}