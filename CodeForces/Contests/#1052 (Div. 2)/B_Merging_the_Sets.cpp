#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> nums(m);
    vector<vector<int>> v;
    for (int i=0;i<n;i++) {
        int l; cin >> l;
        vector<int> s(l, 0);
        for (int j=0;j<l;j++) {
            int a; cin >> a;
            s[j] = a;
            nums[a-1]++;
        }
        v.push_back(s);
    }

    for (int elm : nums) {
        if (elm == 0) {
            cout << "NO\n";
            return;
        }
    }

    int cnt = 1;
    for (vector<int>& s : v) {
        bool flag = false;
        for (int elm : s) {
            if (nums[elm-1] == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) cnt++;
    }

    cout << (cnt >= 3 ? "YES" : "NO") << "\n";

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