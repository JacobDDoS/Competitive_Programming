#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    vector<int> nums(3);
    for (int i=0;i<3;i++) {
        cin >> nums[i];
    }
    for (int i=0;i<3;i++) {
        for (int j=i+1;j<3;j++) {
            if (nums[i] + nums[j] >= 10) {
                cout << "YES\n";
                return;
            }
        }
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