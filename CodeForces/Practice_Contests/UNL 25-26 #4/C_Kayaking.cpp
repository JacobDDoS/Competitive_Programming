#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n*2);
    for (int i=0;i<n*2;i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ptr1 = 0, ptr2 = 1;
    int ans = 999999, temp =0;
    for (int i=0;i<n*2;i++) {
        for (int j=1;j<n*2;j++) {
            temp = 0;
            ptr1 = 0, ptr2 = 1;
            while (ptr1 < n*2) {
                while (ptr1 == i || ptr1 == j) {
                    ptr1++;
                }
                while (ptr2 == i || ptr2 == j || ptr2 <= ptr1) {
                    ptr2++;
                }
                if (ptr2 >= 2*n) break;
                temp += nums[ptr2] - nums[ptr1];
                ptr1 += 2;
                ptr2 += 2;
            }
            ans = min(ans, temp);
        }
    }
    cout << ans;
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
}