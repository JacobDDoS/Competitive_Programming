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
    string s = "L";
    bool flag = true;
    int ans = 0;
    for (int i=1;i<n;i++) {
        if (nums[i] == nums[i-1]) {
            if (s[i-1] == 'L') {
                s.push_back('R');
            } else {
                s.push_back('L');
            }
        } else if (nums[i]+1 == nums[i-1]) {
            if (s[i-1] != 'R') {flag=false;break;}
            s.push_back('R');
        } else if (nums[i] == nums[i-1] + 1) {
            if (s[i-1] != 'L') {flag=false;break;}
            s.push_back('L');
        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        int cnt = 1;
        for (int i=1;i<n;i++) {
            if (s[i] == 'R') cnt++;
        }
        if (cnt != nums[0]) flag = false;
    }

    ans += (flag ? 1 : 0);

    // cout << "test: " << ans << " with " << cnt << " == " << nums[0] << endl;

    s = "R";
    flag = true;
    for (int i=1;i<n;i++) {
        if (nums[i] == nums[i-1]) {
            if (s[i-1] == 'L') {
                s.push_back('R');
            } else {
                s.push_back('L');
            }
        } else if (nums[i]+1 == nums[i-1]) {
            if (s[i-1] != 'R') {flag=false;break;}
            s.push_back('R');
        } else if (nums[i] == nums[i-1] + 1) {
            if (s[i-1] != 'L') {flag=false;break;}
            s.push_back('L');
        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        int cnt = 1;
        for (int i=1;i<n;i++) {
            if (s[i] == 'R') cnt++;
        }
        if (cnt != nums[0]) flag = false;
    }

    ans += (flag ? 1 : 0);

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