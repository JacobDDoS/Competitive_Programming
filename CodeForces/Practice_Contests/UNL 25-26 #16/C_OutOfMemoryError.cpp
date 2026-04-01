#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m, h; cin >> n >> m >> h;
    vector<int> nums(n), lastChanged(n, 0), current(n);
    int lastReset = -1;
    for (int i=0;i<n;i++) cin >> nums[i];
    for (int i=0;i<n;i++) current[i] = nums[i];
    for (int time=1;time<=m;time++) {
        int idx, c; cin >> idx >> c;
        idx--;

        if (lastChanged[idx] < lastReset) {
            current[idx] = nums[idx] + c;
        } else {
            current[idx] += c;
        }

        if (current[idx] > h) {
            lastReset = time;
            current[idx] = nums[idx];
        }

        lastChanged[idx] = time;
    }

    for (int i=0;i<n;i++) {
        if (lastChanged[i] < lastReset) {
            current[i] = nums[i];
        }
    }
    for (int a : current) cout << a << " ";
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