#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull; 

using namespace std;

int main() {
    ll n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    ll maxProfit = 0;
    ll maxIndex = 0;
    for (ll i=0;i<n;i++) {
        if ((n-i)*nums[i] > maxProfit) {
            maxProfit = (n-i)*nums[i];
            maxIndex = i;
        }
    }

    cout << maxProfit << " " << nums[maxIndex] << '\n';
}