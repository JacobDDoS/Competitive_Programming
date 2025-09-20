#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n*2, 0);
    int cur = n;
    for (int i=0;i<2*n;i++) {
        if (cur <= 1) break;
        if (nums[i] == 0) {
            nums[i] = cur;
            if (cur != n) {
                nums[i+2*cur] = cur;
            } else {
                nums[i+cur] = cur;
            }
            cur--;
        }
    }
    for (int i=0;i<n*2;i++) {
        cout << (nums[i] == 0 ? 1 : nums[i]) << " ";
    }
    cout << endl;
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