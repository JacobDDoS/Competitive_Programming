#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> nums(n, 0);
    for (int i=1;i<=n;i++) {
        if (s[i-1] == '1') {
            nums[i-1] = i;
        }
    }

    for (int i=0;i<n;i++) {
        if (nums[i] == 0) {
            int ptr1=i, ptr2=i;
            while (ptr2 < n && nums[ptr2] == 0) {
                ptr2++;
            }
            ptr2--;
            if (ptr1 == ptr2) {
                cout << "NO\n";
                return;
            }
            int cur = ptr2+1;
            for (;ptr1<=ptr2;ptr1++) {
                nums[ptr1] = cur;
                cur--;
            }
        }
    }

    cout << "YES\n";
    for (int elm : nums) {
        cout << elm << " ";
    }
    cout << "\n";
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