#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    string ans = "L";
    int cnt = 1, rightPtr = n-1;
    bool inc = true;
    for (int i=1;i<n && i <= rightPtr;i++) {
        if (cnt == 3 && i != rightPtr) {
            if (inc) {
                if (nums[rightPtr] > nums[i]) {
                    ans.push_back('R');
                    ans.push_back('L');
                    rightPtr--;
                } else {
                    ans.push_back('L');
                    ans.push_back('R');
                    rightPtr--;
                }
                inc = false;
                cnt = 3;
            } else {
                if (nums[rightPtr] > nums[i]) {
                    ans.push_back('L');
                    ans.push_back('R');
                    rightPtr--;
                } else {
                    ans.push_back('R');
                    ans.push_back('L');
                    rightPtr--;
                }
                inc = true;
                cnt = 3;
            }
            continue;
        }

        // General case
        if (nums[i] > nums[i-1]) {
            if (inc) {
                cnt++;
            } else {
                inc = true;
                cnt = 2;
            }
        } else {
            if (!inc) {
                cnt++;
            } else {
                inc = false;
                cnt = 2;
            }
        }
        ans.push_back('L');
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