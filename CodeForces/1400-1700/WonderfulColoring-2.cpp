// Author: JacobDDoS 
// Date: 12/10/22
// Problem: Wonderful Coloring - 2

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    map<int, int> mpNums;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        mpNums[nums[i]]++;
    }

    map<int, set<int>> colorsThatNeedInt;

    int giveToColor = 1;
    for (auto& pr : mpNums) {
        if (pr.second >= k) {
            for (int i=1;i<=k;i++) {
                colorsThatNeedInt[pr.first].insert(i);
            }
        } else {
            for (int i=0;i<pr.second;i++) {
                if (giveToColor > k) {
                    giveToColor = 1;
                }
                colorsThatNeedInt[pr.first].insert(giveToColor);
                giveToColor++;
            }
        }
    }

    map<int, bool> hasExtra;
    if (giveToColor > k) {
        giveToColor = 1;
    }
    giveToColor--;
    for (int i=giveToColor;i>0;i--) {
        hasExtra[i] = true;
    }

    for (int i=0;i<n;i++) {
        set<int>& st = colorsThatNeedInt[nums[i]];
        int toGiveTo = *st.begin();
        st.erase(toGiveTo);
        if (hasExtra[toGiveTo]) {
            hasExtra[toGiveTo] = false;
            nums[i] = 0;
            continue;
        }
        nums[i] = toGiveTo;
    }


    for (int i=0;i<n;i++) {
        cout << nums[i] << " ";
    }
    cout << '\n';

}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}