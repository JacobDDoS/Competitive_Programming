#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    string s; cin >> s;

    int ptr = 0;
    ll ans = 0;
    bool capsLockOn = false;
    int idx = 0;

    int curNumOfSameChar = 0;
    vector<int> nums;
    if (s[0] == 'A') {
        nums.push_back(0);
    }

    vector<int> cheapestWithNoCap;
    vector<int> cheapestWithCap;
    for (int i=0;i<s.size();i++) {
        while (i+curNumOfSameChar < s.size() && s[i+curNumOfSameChar] == s[i]) {
            curNumOfSameChar++;
        }
        nums.push_back(curNumOfSameChar);
        i += curNumOfSameChar-1;
        curNumOfSameChar = 0;
    }

    // for (int i = 0;i<nums.size();i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    for (int i=0;i<nums.size();i++) {
        //Note that if i is even, then the chars are all 'a'
        //Find cheapest with no caps lock
        int lastCheapNC = 0, lastCheapC = z;
        if (cheapestWithNoCap.size() != 0) {
            lastCheapNC = cheapestWithNoCap[cheapestWithNoCap.size()-1];
            lastCheapC = cheapestWithCap[cheapestWithCap.size()-1];
        }

        if (!(i&1)) {
            cheapestWithNoCap.push_back(min(lastCheapNC + nums[i]*x, lastCheapC + z + nums[i]*x));
        } else {
            cheapestWithNoCap.push_back(min(lastCheapNC + nums[i]*y, lastCheapC+nums[i]*x+z));
        }
        //Find cheapest with caps lock

        if (!(i&1)) {
            cheapestWithCap.push_back(min(lastCheapC + nums[i]*y, lastCheapNC+nums[i]*x+z));
        } else {
            cheapestWithCap.push_back(min(lastCheapC + nums[i]*x, lastCheapNC+z+nums[i]*x));
        }
    }

    // for (int i : cheapestWithNoCap) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // for (int i : cheapestWithCap) {
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << min(cheapestWithCap[cheapestWithCap.size()-1], cheapestWithNoCap[cheapestWithNoCap.size()-1]) << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // int n;
    // cin >> n;
    // while (n--) {
    //     solve();
    // }
    solve();
}