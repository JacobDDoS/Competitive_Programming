#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int count(vector<int>& s, int low, int high) {
    auto start = lower_bound(s.begin(), s.end(), low) - s.begin();
    auto end = lower_bound(s.begin(), s.end(), high+1) - s.begin();
    return end-start;
}

void solve()
{
    int n; cin >> n;
    vector<int> nums(n), mex(n), lastIdx(n), ans(n), lastOcc(n+1, 0);
    map<int, vector<int>> mp;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mp[nums[i]].push_back(i);
    }

    if (nums[0] == 0) {
        mex[0] = 1;
        lastIdx[0] = 1;
        ans[0] = 0;
        lastOcc[0] = 1;
    } else {
        mex[0] = 0;
        lastIdx[0] = 1;
        ans[0] = 1;
        lastOcc[nums[0]] = 1;
    }
    for (int i=1;i<n;i++) {
        lastOcc[nums[i]] = i+1;
        if (nums[i] == mex[i-1]) {
            int tempAns = 0, tempPen = 0, tempBestMex = 0, tempBestLastIdx = 0;
            for (int tempMex=0;tempMex<=n;tempMex++) {
                if (tempMex != nums[i]) {
                    int potential = i-lastOcc[tempMex]-tempPen + count(mp[tempMex-1], lastIdx[i-1], lastOcc[tempMex]-1);
                    if (tempAns < potential) {
                        tempAns = potential;
                        tempBestMex = tempMex;
                        tempBestLastIdx = lastOcc[tempMex];
                    }
                }
                tempPen += count(mp[tempMex], lastIdx[i-1], i);
                if (lastOcc[tempMex] == 0) break;
            }
            ans[i] = tempAns;
            mex[i] = tempBestMex;
            lastIdx[i] = tempBestLastIdx;
        } else if (nums[i] > mex[i-1]) {
            ans[i] = ans[i-1]+1;
            mex[i] = mex[i-1];
            lastIdx[i] = lastIdx[i-1];
        } else if (nums[i] < mex[i-1]) {
            ans[i] = ans[i-1];
            mex[i] = mex[i-1];
            lastIdx[i] = lastIdx[i-1];
        }
    }

    for (int elm : ans) {
        cout << elm << " ";
    }
    cout << endl;
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