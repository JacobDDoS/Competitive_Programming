#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> nums(n);
    vector<bool> good(n, false);
    map<int, vector<int>> pos;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        pos[nums[i]].push_back(i);
    }

    int ptr = 0, ans = 0;
    for (auto itr=pos.rbegin();itr!=pos.rend();itr++) {
        for (int i : itr->second) {
            if ((i > 0 && good[i-1]) || (i < n-1 && good[i+1])) {
                good[i] = true;
                int ptrL = i-1, ptrR=i+1;
                while (ptrL > 0 && good[ptrL] == false && nums[ptrL] == itr->first) {
                    good[ptrL] = true;
                    ptrL++;
                }
                while (ptrR < n && good[ptrR] == false && nums[ptrR] == itr->first) {
                    good[ptrR] = true;
                    ptrR++;
                }
            } 
        }
        for (int i : itr->second) {
            if ((i > 0 && good[i-1]) || (i < n-1 && good[i+1])) {
                good[i] = true;
                int ptrL = i-1, ptrR=i+1;
                while (ptrL > 0 && good[ptrL] == false && nums[ptrL] == itr->first) {
                    good[ptrL] = true;
                    ptrL++;
                }
                while (ptrR < n && good[ptrR] == false && nums[ptrR] == itr->first) {
                    good[ptrR] = true;
                    ptrR++;
                }
            } else {
                good[i] = true;
                ans++;
                int ptrL = i-1, ptrR=i+1;
                while (ptrL > 0 && good[ptrL] == false && nums[ptrL] == itr->first) {
                    good[ptrL] = true;
                    ptrL++;
                }
                while (ptrR < n && good[ptrR] == false && nums[ptrR] == itr->first) {
                    good[ptrR] = true;
                    ptrR++;
                }
            }
        }   
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