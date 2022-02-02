// This is the actual code I used to answer the first silver problem in January USACO 2022
// Obviously, I still have so much to learn. But that's what makes this fun!

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, bool> pos;
set<ll> posNums;
ll maybeAns = 1000000000000000001;
// vector<ll> posNumsVec;

ll howManyAway(ll b, ll curPos) {
    ll re = 0;
    ll total = 0;
    while (curPos != b) {
        re = 0;
        auto nextOne = upper_bound(posNums.begin(), posNums.end(), curPos);
        // if (nextOne == posNums.end()) break;
        ll nextOneNum = *nextOne;
        // cout << "nextOneNum: " << nextOneNum << endl;
        // cout << "re: " << re << endl;
        // cout << "curPos: " << curPos << endl;
        if (nextOneNum/2 - curPos < 0) {
            re = nextOneNum - curPos;
        } else {
            re += nextOneNum/2 - curPos;
        }
        // cout << "re: " << re << endl;
        curPos += re;
        if (curPos != nextOneNum) {
            re++;
            curPos*=2;
        }
        // cout << "re: " << re << " curPos " << curPos << endl;
        if (curPos != nextOneNum) {
            re += (nextOneNum-curPos);
            curPos += (nextOneNum-curPos);
        }
        total += re;
    }
    return total;
}

void solve() {
    pos.clear();
    posNums.clear();
    maybeAns = 1000000000000000001;
    ll a, b; cin >> a >> b;
    ll cp = b;
    ll ans = 0;

    pos[b] = true;
    posNums.insert(b);
    // posNumsVec.push_back(b);
    while (b > 1) {
        // cout << "b: " << b << endl;
        if (!(b & 1)) {
            b /= 2;
        } else {
            b--;
            pos[b] = true;
            posNums.insert(b);
            b/=2;
        }
        pos[b] = true;
        // posNumsVec.push_back(b);
        posNums.insert(b);
    }

    b = cp;

    while (a != b) {
        // cout << "a: " << a << "ans: " << ans << endl;
        if (a > b) {
            if (a % 2 == 1) {  
                a++;
                ans++;
            } else {
                a /= 2;
                ans++;
            }
        } else {
            // cout << "a: " << a << endl;
            if (a <= b/2) {
                // cout << "maybeAns before: " << maybeAns << endl;
                maybeAns = min(maybeAns, howManyAway(b, a)+ans);
                // cout << "a: " << a << " maybeAns: " << maybeAns << "ans: " << ans << endl;
            }
            if (pos[a]) {
                // cout << "howMany: " << howManyAway(b, a) << endl;
                ans += howManyAway(b, a);
                break;
            } else if (pos[a+1]) {
                ans += howManyAway(b, a+1);
                ans++;
                break;
            } else {
                if (a & 1) {
                    a++;
                    ans++;
                } 
                if (pos[a+1]) {
                    ans += howManyAway(b, a+1);
                    ans++;
                    break;
                }
                ll num = *upper_bound(posNums.begin(), posNums.end(), a);
                maybeAns = min(maybeAns, howManyAway(b, num) + (num-a) + ans);
                if (a <= b/2) {
                    // cout << "maybeAns before: " << maybeAns << endl;
                    maybeAns = min(maybeAns, howManyAway(b, a)+ans);
                    // cout << "a: " << a << " maybeAns: " << maybeAns << "ans: " << ans << endl;
                }
                a/=2;
                ans++;
            }

            // if (a <= b/2) {
            //     ans += (b/2 - a);
            //     a += (b/2 - a);
            //     a *= 2;
            //     ans++;
            //     if (b % 2 == 1) {
            //         ans++;
            //     }
            //     break;
            // } else {
            //     ans += b-a;
            //     break;
            // }
        }
    }

    cout << min(maybeAns, ans) << '\n';
}

int main() {
    int t; cin >> t;
    
    while (t--) {
        solve();
    }
}