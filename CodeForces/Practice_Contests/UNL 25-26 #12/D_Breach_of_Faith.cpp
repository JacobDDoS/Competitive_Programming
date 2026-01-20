#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> nums(2*n);
    map<ll, bool> mp;
    for (int i=0;i<2*n;i++) {
        cin >> nums[i];
        mp[nums[i]] = true;
    }
    sort(nums.begin(), nums.end());
    srand(time(NULL));

    ll sum = 0;
    for (int i=0;i<n;i++) {
        sum += nums[2*i] - nums[2*i+1];
    }
    while (mp[sum] || sum < 1) {
        sum = 0;
        random_shuffle(nums.begin(), nums.end());
        for (int i=0;i<n;i++) {
            sum += nums[2*i] - nums[2*i+1];
        }
    }

    cout << sum << " ";
    for (ll i : nums) cout << i << " ";
    cout << '\n';


    // int lPtr = 0, rPtr = 2*n-1;
    // vector<ll> res(2*n);
    // long long sum = 0;
    // for (int i=0;i<n;i++) {
    //     res[2*i+1] = nums[lPtr++];
    //     res[2*i] = nums[rPtr--];
    //     sum += res[2*i] - res[2*i+1];
    // }

    // if (mp[sum]) {
        
    // }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}