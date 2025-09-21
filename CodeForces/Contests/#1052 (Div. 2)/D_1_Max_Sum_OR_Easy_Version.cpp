#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int highestPowOfTwo(int x) {
    for (int i=30;i>=0;i--) {
        if (x & (1<<i)) {
            return i;
        }
    }
    return 0;
}

void solve()
{
    int l, r; cin >> l >> r;
    vector<bool> used(r+1, false);
    vector<int> nums(r+1);
    long long ans = 0;

    vector<int> powsOfTwo = {1};
    for (int i=1;i<31;i++) {
        powsOfTwo.push_back(powsOfTwo[i-1] | (1<<i));
    }

    for (int i=r;i>0;i--) {
        if (used[i]) continue;
        int target = i^powsOfTwo[highestPowOfTwo(i)];
        while (used[target]) {
            target ^= (target & (-target));
        }

        used[i] = true;
        used[target] = true;
        ans += (i|target)*2;
        nums[i] = target;
        nums[target] = i;
    }

    cout << ans << '\n';
    for (int elm : nums) {
        cout << elm << " ";
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