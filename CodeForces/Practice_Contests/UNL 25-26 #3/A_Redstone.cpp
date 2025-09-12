#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    unordered_set<int> nums;
    int a;
    bool flag = false;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (nums.count(a)) {
            flag = true;
        } 
        nums.insert(a);
    }

    if (flag) {
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