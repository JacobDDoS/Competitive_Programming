#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m; cin >> m;
    vector<int> nums(m);
    for (int i=0;i<m;i++) {
        cin >> nums[i];
    }

    int step = 2;
    int curIdx = 0;
    int ans = 0;
    while (step <= m) {
        int sizeOfSection = step/2;
        curIdx = 0;

        while (curIdx < m) {
            int beginFirst = curIdx, endFirst = curIdx + step/2-1, beginSecond = curIdx + step/2, endSecond = curIdx + step-1;
            // cout << nums[beginFirst] << " " << nums[beginSecond] << endl;
            if (nums[beginSecond] >= nums[endFirst]) {
                ;
            } else if (nums[beginFirst] >= nums[endSecond]) {
                ans++;
                for (int i=curIdx;i<=endFirst;i++) {
                    swap(nums[i], nums[i + step/2]);
                }
            } else {
                cout << "-1\n";
                return;
            }
            curIdx += step;
        }


        step *= 2;
    }

    cout << ans << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}