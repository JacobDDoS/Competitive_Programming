// Credit To Andrew Bartling (KHS CPC) for most of the following code

#include <iostream>
#include <cmath>
#include <vector>
#define l long
#define ll long long
using namespace std;



int main() {
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    vector<ll> dif(n);
    dif[0] = -nums[0];
    for (int i=1;i<n;i++) {
        dif[i] = nums[i-1] - nums[i];
    }

    ll ans = abs(dif[0]);
    for (int i=1;i<n;i++) {
        ans += abs(dif[i-1] - dif[i]);
    }

    cout << ans;
}

