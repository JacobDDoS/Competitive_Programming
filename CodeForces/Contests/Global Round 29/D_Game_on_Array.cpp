#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    ll a=0, b=0;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        mp[nums[i]]++;
    }

    vector<pair<int, int>> v;
    for (auto& pr : mp) {
        v.push_back(make_pair(pr.second, pr.first));
    }

    bool aTurn = true;
    int vPtr = 0;
    int elm = v[vPtr].second, elmOcc = v[vPtr].first;
    while (vPtr < nums.size()) {
        elm = v[vPtr].second, elmOcc = v[vPtr].first;
        auto mpItr = mp.find(elm);
        vector<int> toRemove;
        do {
            if (mpItr == mp.begin()) {
                if (aTurn) {
                    a += ((mpItr->first+1)/2 * mpItr->second);
                    b += (mpItr->first/2 * mpItr->second);
                } else {
                    a += (mpItr->first/2 * mpItr->second);
                    b += ((mpItr->first+1)/2 * mpItr->second);
                }
            } else {
                auto copyItr = mpItr;
                copyItr--;
                if (aTurn) {
                    a += ((mpItr->first-copyItr->first+1)/2 * mpItr->second);
                    b += ((mpItr->first-copyItr->first)/2 * mpItr->second);
                } else {
                    a += ((mpItr->first-copyItr->first)/2 * mpItr->second);
                    b += ((mpItr->first-copyItr->first+1)/2 * mpItr->second);
                }
                mp[copyItr->first] += mpItr->second;
            }

            if (mpItr->second & 1) {
                aTurn = !aTurn;
            }

            toRemove.push_back(mpItr->first);
            if (mpItr != mp.begin()) {
                mpItr--;
            }
        } while (mpItr != mp.begin());
        for (int elm : toRemove) {
            mp.erase(elm);
        }

        while (vPtr < nums.size() && v[vPtr].second <= elm) {
            vPtr++;
        }
    }
    cout << a << " " << b << endl;
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