// Author: JacobDDoS 
// Date: 7/16/22
// Problem: C
 
/* test 5477
6 2
1 1 1 1 3 2
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;
 
void solve() {
    int n, q; cin >> n >> q;
    vector<int> nums(n);
    string ans = "";
    map<int, vector<int>> index;
 
    vector<int> bestToRemove;
    vector<int> bestToAdd;
 
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (nums[i] <= q) {
            ans.push_back('1');
            index[nums[i]].push_back(i);
        } else {
            ans.push_back('0');
        }
    }
 
    int additional = q;
 
    for (int i=n-1;i>=0;i--) {
        if (nums[i] > q && additional) {
            ans[i] = '1';
            additional--;
        } else {
            if (additional) {
                int tempQ = q;
                vector<int> toRemove;
                vector<int> toAdd;
                for (;i>=0;i--) {
                    if (nums[i] <= q || !additional || !tempQ) {
                        continue;
                    }
                    vector<int>& indxOfCurQ = index[tempQ];
                    vector<int>::iterator upper;
                    upper = upper_bound(indxOfCurQ.begin(), indxOfCurQ.end(), i);
                    tempQ--;
                    additional--;
                    for (int j=indxOfCurQ.size()-1;j>=upper-indxOfCurQ.begin();j--) {
                        if (additional) {
                            additional--;
                        } else {
                            toRemove.push_back(indxOfCurQ[j]);
                        }
                    }
                    toAdd.push_back(i);       
 
                    if (toAdd.size() > toRemove.size() && toAdd.size() - toRemove.size() > bestToAdd.size() - bestToRemove.size()) {
                        bestToAdd = toAdd;
                        bestToRemove = toRemove;
                    }
 
 
                }
                if (bestToAdd.size() > bestToRemove.size()) {
                    for (int i=0;i<bestToAdd.size();i++) {
                        ans[bestToAdd[i]] = '1';
                    }
                    for (int i=0;i<bestToRemove.size();i++) {
                        ans[bestToRemove[i]] = '0';
                    }
                }
            }
            break;
        }
    }


    for (int i=0;i<n;i++) {
        if (ans[i] == '1' && nums[i] > q) {
            if (q) {
                q--;
            } else {
                ans[i] = '0';
            }
        }
    }
 
 
    cout << ans << "\n";
 
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