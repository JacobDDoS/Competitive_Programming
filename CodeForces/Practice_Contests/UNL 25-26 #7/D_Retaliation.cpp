#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<long long> nums(n+1);
    for (int i=1;i<=n;i++) {
        cin >> nums[i];
    }
    bool firstOp = (nums[1] < nums[2]);
    long long dif = abs(nums[1] - nums[2]);

    long long div = -1;
    for (int i=1;i<=n;i++) {
        int curDif;
        if (firstOp) {
            curDif = i*dif;
        } else {
            curDif = (n+1-i)*dif;
        }

        // cout << "firstOp: " << (firstOp ? "true" : "false") << endl;
        // cout << nums[i] << ", curdif: " << curDif << endl;
        if (div == -1) {
            div = (nums[i]-curDif)/(n+1);
        }
        if ((nums[i] - curDif) < 0 || (nums[i] - curDif) % (n+1) != 0 || (nums[i]-curDif)/(n+1) != div) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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