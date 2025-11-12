#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    int sum = 0;
    bool flag = false;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        sum += nums[i];
        if (nums[i] % 3 == 1) {
            flag = true;
        }
    }

    if (sum % 3 == 0) {
        cout << "0\n";
    } else if (sum % 3 == 1) {
        if (flag) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    } else {
        cout << "1\n";
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