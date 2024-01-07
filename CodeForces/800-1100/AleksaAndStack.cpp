#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int s; cin >> s;
    
    vector<ll> nums;
    nums.push_back(2);
    nums.push_back(3);
    for (int i=2;i<s;i++) {
        ll sum = nums[i-2] + nums[i-1];
        for (int j=nums[i-1]+1;;j++) {
            if (j*3 % sum != 0) {
                nums.push_back(j);
                break;
            }
        }
    }

    for (int i=0;i<s;i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
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