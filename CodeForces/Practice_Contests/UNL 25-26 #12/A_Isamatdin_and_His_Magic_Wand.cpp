#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    bool e = false, o = false;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (nums[i] & 1) {
            o = true;
        } else {
            e = true;
        }
    }

    if (e && o) {
        sort(nums.begin(), nums.end());
    }

    for (int i : nums) {
        cout << i << " ";
    }
    cout << '\n';
    

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