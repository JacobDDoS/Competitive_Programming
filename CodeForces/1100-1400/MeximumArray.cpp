// Author: JacobDDoS 
// Date: 9/29/22
// Problem: A. Meximum Array 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;



void setLookingFor(int& lookingFor, map<int, int>& mp, int& n) {
for (int i=0;i<=n;i++) {
        if (mp[i] == 0) {
            lookingFor = i-1;
            break;
        }
    }
}


void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    vector<int> ans;
    map<int, int> mp;
    int lookingFor = 0;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
   
    for (int i=0;i<n;i++) {
        mp[nums[i]]++;
    }

    setLookingFor(lookingFor, mp, n);
    
    int currentlyHas = 0;
    map<int, bool> hasNum;
    for (int i=0;i<n;i++) {
        if (!hasNum[nums[i]] && nums[i] <= lookingFor) {
            currentlyHas++;
            hasNum[nums[i]] = true; 
        } 
        mp[nums[i]]--;

        if (currentlyHas == lookingFor+1) {
            hasNum.clear();
            ans.push_back(lookingFor+1);
            currentlyHas = 0;
            setLookingFor(lookingFor, mp, n);
        } 
    }

    cout << ans.size() << '\n';
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

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