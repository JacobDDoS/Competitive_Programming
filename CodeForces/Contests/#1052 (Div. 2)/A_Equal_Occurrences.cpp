#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mp[nums[i]]++;
    }

    int maxElm = 0;
    for (auto& pr : mp) {
        maxElm = max(maxElm, pr.second);
    }
    
    int ans = 0, temp = 0;
    for (int i=1;i<=maxElm;i++) {
        temp = 0;
        for (auto& pr : mp) {
            if (pr.second >= i) {
                temp += i;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
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