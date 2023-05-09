// Author: JacobDDoS 
// Date: 5/8/23
// Problem: Pretend and Append 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int left=0,right=n-1;
    while (right > left) {
        if ((s[right] == '1' && s[left] == '0') || (s[right] == '0' && s[left] == '1')) {
            right--;
            left++;
        } else {
            break;
        }
    }

    cout << right - left +1 << '\n';
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