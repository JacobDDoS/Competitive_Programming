#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> nums(n, 0), prefix(n+1, 0);
    int total = 0;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        if (a <= k) nums[i] = 1;
        total += nums[i];
    }

    cout << "total: " << total << endl;

    int curSum = 0, minLeft = 9999999, maxRight = -1;
    for (int i=0;i<n;i++) {
        curSum += nums[i];
        if (curSum*2 >= (i+1)) {
            minLeft = min(minLeft, i);
        }

        if (i < n-2 && (total-curSum)*2 > (n-i)) {
            cout << "total: " << total << " curSum: " << curSum << " compared to " << (n-(i+1)) << endl;
            cout << "1 YES\n";
            return;
        }

    }

    curSum = 0;
    for (int i=n-1;i>=0;i--) {
        curSum += nums[i];
        if (curSum*2 >= (i+1)) {
            maxRight = max(i, maxRight);
        }

        if (i > 1 && (total-curSum)*2 > i) {
            cout << "total: " << total << " curSum: " << curSum << " compared to " << i-1 << endl;
            cout << "2 YES\n";
            return;
        }

    }
    if (minLeft < maxRight-1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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