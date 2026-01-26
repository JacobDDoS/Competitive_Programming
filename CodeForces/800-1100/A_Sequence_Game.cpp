#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    int x; cin >> x;
    bool h = false, l = false;
    for (int i=0;i<n;i++) {
        if (nums[i] == x) {
            cout << "YES\n";
            return;
        } else if (nums[i] > x) {
            h = true;
        } else {
            l = true;
        }
    }
    if (h && l) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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