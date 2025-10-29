#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    vector<bool> exists(n+1, false);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        exists[nums[i]] = true;
    }

    for (int i=0;i<n;i++) {
        if (!nums[i]) {
            for (int j=n;j>=1;j--) {
                if (!exists[j]) {
                    nums[i] = j;
                    exists[j] = true;
                    break;
                }
            }
            break;
        }
    }

    for (int i=n-1;i>=0;i--) {
        if (!nums[i]) {
            for (int j=1;j<=n;j++) {
                if (!exists[j]) {
                    nums[i] = j;
                    break;
                }
            }
            break;
        }
    }

    int l=9999999, r=-1; 
    for (int i=0;i<n;i++) {
        if (nums[i] && nums[i] != i+1) {
            l = min(l, i);
            r = max(nums[i]-1, r);
        }
    }

    cout << (r!=-1 ? r-l+1 : 0)<< endl;

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